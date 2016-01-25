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
typedef pair<int,int> ii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

vii val;
vector<vi> dp;

int change(int x, int y) {
	if (x < 0 || y < 0)
		return INF;
	if (x == 0 && y == 0)
		return dp[x][y] = 0;
	int ans = INF;
	for (int i = 0; i < val.size(); i++) {
		int cur;
		if (x - val[i].first >= 0 && y - val[i].second >= 0 && dp[x - val[i].first][y - val[i].second] != INF)
			cur = dp[x - val[i].first][y - val[i].second];
		else cur = change(x - val[i].first, y - val[i].second);
		ans = min(ans, 1 + cur);
	}
	return dp[x][y] = ans;
}

int main(){
	int n, a, b, num, sum;
	cin >> n;
	while (n--) {
		val.clear();
		cin >> num >> sum;
		while (num--) {
			cin >> a >> b;
			val.push_back(ii(a, b));
		}
		sum *= sum;
		dp.assign(sqrt(sum)+2, vi(sqrt(sum)+2, INF));
		int ans = INF;
		for (int i = 0; i < sqrt(sum/2); i++) {
			if (ceil(sqrt(sum - i*i)) == sqrt(sum - i*i)) {
	cout << i << " " << sqrt(sum - i*i) << endl;
				ans = min(ans, change(i, sqrt(sum-i*i)));
			}
		}
		if (ans == INF)
			cout << "not possible" << endl;
		else cout << ans << endl;
	}
	return 0;
}
