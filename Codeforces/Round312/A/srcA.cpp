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

int main() {
	int n, x, a;
	cin >> n;
	vii left, right;
	while (n--) {
		cin >> x >> a;
		if (x < 0)
			left.push_back(ii(-x, a));
		else
			right.push_back(ii(x, a));
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int sum = 0;
	if (left.size() > right.size()) {
		int i = 0;
		for (; i < right.size(); i++) {
			sum += left[i].second;
			sum += right[i].second;
		}
		sum += left[i].second;
	} else if (left.size() < right.size()) {
		int i = 0;
		for (; i < left.size(); i++) {
			sum += left[i].second;
			sum += right[i].second;
		}
		sum += right[i].second;
	} else {
		int i = 0;
		for (; i < left.size(); i++) {
			sum += left[i].second;
			sum += right[i].second;
		}
	}
	cout << sum << endl;
	return 0;
}
