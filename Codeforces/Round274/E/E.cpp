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

int total;
vi p;
vi value;
map<int, vi> adj;

void dfs(int u){
	int max = 0, vertex = -1;
	total += value[u];
//	cout << "u " << u << " " << total << adj[u].size() << endl;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (max < value[v]){
			max = value[v];
			vertex = v;
		}
	}
	if (vertex != -1){
		p.push_back(vertex);
		dfs(vertex);
	}
}

int main(){
	int c, cs = 0;
	scanf("%d", &c);
	while (c--){
		total = 0;
		p.clear();
		value.clear();
		adj.clear();
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++){
			int a; scanf("%d", &a);
			value.push_back(a);
		}
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < adj[i].size(); j++)
//				cout << adj[i][j] << " ";
//			cout << endl;
//		}
		dfs(0);
		int last = p[p.size()-1];
		printf("Case %d: %d %d\n", ++cs, total, last);
	}
}
