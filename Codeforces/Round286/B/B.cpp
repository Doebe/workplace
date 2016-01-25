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


vector<vii> adj;
int u, v;
vi visited;

bool dfs(int a, int c){
//	cout << a << " " << c << endl;
	visited[a] = 1;
	bool found = false;
	for (int i = 0; i < adj[a].size(); i++){
//		cout << "color "<<adj[u][i].first << endl;
		if (adj[a][i].second == c){
			if (adj[a][i].first == v){
//				cout << "found" << v << endl;
				return true;
			}
			if (!visited[adj[a][i].first])
				found |= dfs(adj[a][i].first, c);
		}
	}
	return found;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	adj.assign(n+1, vii());
	for (int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back(ii(b, c));
		adj[b].push_back(ii(a, c));
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++){
		vi ans;
		vi clr(m+1, 0);
		scanf("%d %d", &u, &v);
		for (int i = 0; i < adj[u].size(); i++){
			int color = adj[u][i].second;
			if (clr[color] == 1)
				continue;
			clr[color] = 1;
			visited.assign(n+1, 0);
			if (dfs(u, color))
				ans.push_back(color);
		}
		cout << ans.size() << endl;
	}
}
