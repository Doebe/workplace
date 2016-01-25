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
typedef vector<ic> vic;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main() {
	int n, m;
	while (scanf("%d %d", &n, &m) && n) {
		double dp[m][n+1];
		char t;
		int r;
		vic type;
		for (int i = 0; i < n; i++) {
			cin >> t >> r;
			type.push_back(ic(r, t));
		}
		for (int i = 0; i < m; i++)
			dp[i][0] = 0;
		for (int j = 1; j < n+1; j++) {
			for (int i = 0; i < m; i++) {
				dp[i][j] = INF;
				if (type[j-1].second == 'R') {
					int radius = (m-1-i) * 10 + 5 + type[j-1].first;
					dp[i][j] = dp[i][j-1] + PI * radius / 2;
					continue;
				}
				if (type[j-1].second == 'L') {
					int radius = i * 10 + 5 + type[j-1].first;
					dp[i][j] = dp[i][j-1] + PI * radius / 2;
					continue;
				}
				int len = type[j-1].first;
				for (int k = 0; k < m; k++) {
					int dif = abs(k-i);
					if (dif * 100 > len)
						continue;
					double path = sqrt(len * len + 100 * dif * dif);
					dp[i][j] = min(dp[i][j], (path + dp[k][j-1]));
				}
			}
		}
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < n+1; j++)
//				printf("%.2lf ", dp[i][j]);
//			cout << endl;
//		}
		double ans = INF;
		for (int i = 0; i < m; i++)
			ans = min(ans, dp[i][n]);
		printf("%.2lf\n", ans);
	}
	return 0;
}
