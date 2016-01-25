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

vi dfs_num, dfs_low, dfs_parent;
vector<bool> articulation_vertex;
map<int, vi> adj;
vi components;
vii bombs;
int dfsNumberCounter, dfsRoot, rootChildren;

void articulationPoint(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for (int j = 0; j < (int)adj[u].size(); j++){
		int v = adj[u][j];
		if (dfs_num[v] == 0){
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;

			articulationPoint(v);

			if (dfs_low[v] >= dfs_num[u]){
//				cout << u << ", " << v << endl;
				articulation_vertex[u] = true;
				components[u]++;
			}

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

bool sortValue(ii x, ii y){
	if (x.second > y.second)
		return true;
	if (x.second == y.second && x.first < y.first)
		return true;
	return false;
}

int main(){
	int n, m, a, b;
	while (cin >> n >> m){
		if (n == 0)
			break;
		adj.clear();
		while (cin >> a >> b){
			if (a == -1)
				break;
			adj[a].push_back(b);
			adj[b].push_back(a);
//				cout << b << " ";
		}
//			cout << endl;
		dfsNumberCounter = 1;
		dfs_num.assign(n+1, 0);
		dfs_low.assign(n+1, 0);
		dfs_parent.assign(n+1, 0);
		articulation_vertex.assign(n, false);
		components.assign(n+1, 0);
		bombs.clear();
		int originalComponents = 0;
		for (int i = 0; i < n; i++){
//			cout << i << ", " << dfs_num[i] << endl;
			if (dfs_num[i] == 0){
				dfsRoot = i;
				originalComponents++;
//				cout << i << endl;
				rootChildren = 0;
				articulationPoint(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1);
				components[i] = rootChildren - 1;
//				cout << dfsRoot << ", " << rootChildren << ", " << articulation_vertex[dfsRoot] << endl;
			}
		}
		for (int i = 0; i < n; i++){
			bombs.push_back(ii(i, originalComponents + components[i]));
		}
		sort(bombs.begin(), bombs.end(), sortValue);
//		cout << 1 << endl;
		for (int i = 0; i < m; i++)
//			cout << i << ", " << dfs_num[i] << ", " << dfs_low[i] << ", " << articulation_vertex[i] << endl;
			cout << bombs[i].first << " " << bombs[i].second << endl;
		cout << endl;
	}
	return 0;
}
