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


int main() {
	ll n, q, d, m, c = 0;
	while (cin >> n >> q && n && q) {
		ll w[n+1];
		for (int i = 1; i <= n; i++)
			cin >> w[i];
		cout << "SET " << ++c << ":" << endl;
		for (int s = 0; s < q; s++) {
			cin >> d >> m;
			ll dp[202][12][21];
			MEM(dp, 0);
			for (int i = 0; i <= n; i++)
				dp[i][0][0] = 1;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= m; j++)
					for (int k = 0; k < d; k++)
						dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][(k+d-(w[i]%d))%d];
			cout << "QUERY " << (s+1) << ": " << dp[n][m][0] << endl;
		}
	}
	return 0;
}
