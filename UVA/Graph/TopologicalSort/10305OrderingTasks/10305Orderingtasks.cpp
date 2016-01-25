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

int n, m, a, b, vis[101];
vector<vector<char> > adj;
vi ts;

void dfs(int u) {
	vis[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        if (!vis[adj[u][i]])
        	dfs(adj[u][i]);
    }
    ts.push_back(u);
}

int main() {
    while (cin >> n >> m){
    	if (n == 0)
    		break;
    	adj.clear();
    	adj.resize(101);
    	ts.clear();
    	MEM(vis, 0);
    	while (m--){
        	cin >> a >> b;
        	adj[a].push_back(b);
        }
    	for (int i = 1; i <= n; i++)
    		if (!vis[i])
    			dfs(i);
    	for (int i = ts.size() - 1; i >= 0; i--)
    		cout << ts[i] << " ";
    	cout << endl;
    }
}
