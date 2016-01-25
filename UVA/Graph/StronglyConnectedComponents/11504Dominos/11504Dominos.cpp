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

vi S, visited;
map<int, vi> adj;
int SCC;

void tarjanSCC(int u){
	visited[u] = 1;
	for (int i = 0; i < adj[u].size(); i++){
		int v = adj[u][i];
		if (visited[v] == 0)
			tarjanSCC(v);
	}
	S.push_back(u);
}

int main(){
	int n;
	cin >> n;
	while (n--){
		int a, b;
		cin >> a >> b;
		SCC = 0;
		while (b--){
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
		}
		visited.assign(a + 1, 0);
		for (int i = 1; i <= a; i++){
//			cout << i << ", " << dfs_num[i] << endl;
			if (visited[i] == 0){
//				cout << i << endl;
				tarjanSCC(i);
			}
		}
		visited.assign(a + 1, 0);
		for (int i = S.size() - 1; i >= 0; i--){
//			cout << S[i] << endl;
			if (visited[S[i]] == 0){
				tarjanSCC(S[i]);
				SCC++;
			}
		}
		cout << SCC << endl;
		adj.clear();
		S.clear();
	}
	return 0;
}
