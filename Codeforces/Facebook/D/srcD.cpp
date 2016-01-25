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

int dp[200010][21];
vector<vi> adj;
vi nodes;

void dfs(int u) {
	for (int i = 0; i < adj[u].size(); i++)
		dfs(adj[u][i]);
	nodes.push_back(u);
}

int main(){
	int t, n;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> n;
		int a, ans = INF;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < 21; j++)
				dp[i][j] = INF;
		adj.clear();
		nodes.clear();
		adj.assign(n+1,vi());
		for (int i = 1; i <= n; i++) {
			cin >> a;
//			adj.push_back(vi());
			if (a == 0)
				continue;
			adj[a].push_back(i);
		}
//		for (int i = 1; i <= n; i++) {
//			cout << i << ": ";
//			for (int j = 0; j < adj[i].size(); j++)
//				cout << adj[i][j] << " ";
//			cout << endl;
//		}
		dfs(1);
		for (int x = 0; x < n; x++) {
			int i = nodes[x];
			if (adj[i].size() == 0) {
				for (int j = 1; j < 21; j++)
					dp[i][j] = j;
				continue;
			}
			for (int j = 1; j < 21; j++) {
				int sum = 0;
				for (int k = 0; k < adj[i].size(); k++) {
					int cur = adj[i][k];
					int mn = INF;
					for (int l = 1; l < 21; l++) {
						if (l == j)
							continue;
						mn = min(mn, dp[cur][l]);
					}
					sum += mn;
				}
				dp[i][j] = min(dp[i][j], sum + j);
			}
		}
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j < 21; j++)
//				cout << dp[i][j] << " ";
//			cout << endl;
//		}
		for (int i = 1; i < 21; i++)
			ans = min(ans, dp[1][i]);
		printf("Case #%d: %d\n", c, ans);
	}
	return 0;
}
