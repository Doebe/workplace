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

int n, m, a, b;
int t;
vector<vi> adj;
vi c;
vi v;

void dfs(int u, int cat) {
//	cout << "come in: " << u << endl;
	v[u] = 1;
	if (!c[u])
		cat = 0;
	else
		cat++;
	if (cat > m)
		return;
	int empty = 0;
	for (int i = 0; i < adj[u].size(); i++)
		if (!v[adj[u][i]]) {
			empty = 1;
			break;
		}
//	cout << u << " " << cat << " " << empty << endl;
	if (!empty) {
		t++;
//			cout << u << endl;
	}
	for (int i = 0; i < adj[u].size(); i++) {
		if (!v[adj[u][i]]) {
//			cout << "next: " << u << " " << adj[u][i] << " " << cat << endl;
			dfs(adj[u][i], cat);
		}
	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		c.push_back(a);
	}
	adj.assign(n, vi());
	v.assign(n, 0);
	t = 0;
	for (int  i = 0; i < n-1; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, 0);
	cout << t << endl;
	return 0;
}
