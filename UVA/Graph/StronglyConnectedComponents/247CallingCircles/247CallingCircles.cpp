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

vi dfs_num, dfs_low, S, visited;
map<int, vi> adj;
map<string, int> msi;
map<int, string> mis;
int dfsNumberCounter;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	S.push_back(u);
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]){
		while (1){
			int v = S.back();
			S.pop_back();
			visited[v] = 0;
			if (u == v){
				cout << mis[v] << endl;
				break;
			}
			cout << mis[v] << ", ";
		}
	}
}

int main(){
	int n, m, cnt = 0;
	while (cin >> n >> m){
		if (n == 0)
			break;
		cnt++;
		if (cnt > 1)
			cout << endl;
		dfs_num.assign(n, -1);
		dfs_low.assign(n, -1);
		visited.assign(n, 0);
		dfsNumberCounter = 0;
		adj.clear();
		msi.clear();
		mis.clear();
		S.clear();
		string a, b;
		for (int i = 0; i < m; i++){
			cin >> a >> b;
			if (!msi.count(a)){
				msi[a] = mis.size();
//				cout << a << ", " << msi[a] << endl;
				mis[msi[a]] = a;
			}
			if (!msi.count(b)){
				msi[b] = mis.size();
//				cout << b << ", " << msi[b] << endl;
				mis[msi[b]] = b;
			}
			adj[msi[a]].push_back(msi[b]);
//			adj[msi[b]].push_back(msi[a]);
		}
		cout << "Calling circles for data set " << cnt << ":" << endl;
		for (int i = 0; i < n; i++)
			if (dfs_num[i] == -1)
				tarjanSCC(i);
	}
	return 0;
}
