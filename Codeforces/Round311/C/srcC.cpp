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

ii len[100010];
int cnt[205];

int main() {
	int n;
	cin >> n;
	MEM(cnt, 0);
	for (int i = 0; i < n; i++)
		cin >> len[i].first;
	for (int i = 0; i < n; i++){
		cin >> len[i].second;
		cnt[len[i].second]++;
	}
	sort(len, len+n);
	int sum = 0;
	int ans = INF;
	int i = n-1, j = n-1;
	while (i >= 0){
		while (j >= 0 && len[j].first == len[i].first)
			cnt[len[j--].second]--;
		int rm = j - (i - j) + 2;
		int c = 0;
		int cur = sum;
		while (rm){
			int tmp = min(rm, cnt[c]);
			cur += tmp * c++;
			rm -= tmp;
		}
//		cout << cur << endl;
		ans = min(ans, cur);
		while (j < i)
			sum += len[i--].second;
	}
	cout << ans << endl;
}
