#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int NEG_INF = -1000000000;

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

map<int, ii> dp;

vi getadj(int n) {
	int l = log10(n) + 1;
	vi digits;
	int nn = n;
	bool hasZero = false;
	for (int i = 0; i < l; ++i) {
		hasZero = hasZero || ((nn % 10) == 0);
		digits.push_back(nn % 10);
		nn /= 10;
	}
	vi ans;

	reverse(digits.begin(), digits.end());

	for (int i = 1; i < (1 << digits.size()); ++i) {
		int nn = n;
		int subfactor = 0;
		int rem = 0;
		bool hasLeadingZero = false;
		bool firstDigit = true;
		for (int j = 0; j < digits.size(); ++j) {
			if (i & (1 << j)) {
				if (firstDigit && digits[j] == 0) {
					hasLeadingZero = true;
					continue;
				}
				firstDigit = false;

				subfactor *= 10;
				subfactor += digits[j];
			} else {
				rem *= 10;
				rem += digits[j];
			}
		}
		if (hasLeadingZero)
			continue;
		if (subfactor > 1 && n % subfactor == 0) {
			if (rem == 0 && !hasZero)
				continue;
//	debug(i);
//	printf("n = %d rem = %d subfactor = %d\n",n,rem,subfactor);
			ans.push_back(rem);
		}
	}
	return ans;
}

void DP(int n) {
	if (dp.count(n))
		return;
	vi ans = getadj(n);
	dp[n] = ii(0, n);
	if (!ans.size())
		return;
	for (int i = 0; i < ans.size(); i++) {
		DP(ans[i]);
		if (dp[ans[i]].first + 1 > dp[n].first) {
			dp[n].first = dp[ans[i]].first + 1;
			dp[n].second = ans[i];
		} else if (dp[ans[i]].first + 1 == dp[n].first)
			dp[n].second = min(dp[n].second, ans[i]);
	}
}

int main() {
	int n;
	while (cin >> n && n) {
		DP(n);
		printf("%d", n);
		while (dp[n].first) {
			printf(" %d", dp[n].second);
			n = dp[n].second;
		}
		printf("\n");
	}
	return 0;
}
