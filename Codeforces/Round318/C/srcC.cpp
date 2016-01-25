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

int g[4002][4002];
int rec = INF;

int main(){
	int n, m, a, b;
	cin >> n >> m;
	MEM(g, 0);
	vii edges;
	vi degree(n, 0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--; b--;
		edges.push_back(ii(a, b));
		g[a][b] = 1;
		g[b][a] = 1;
		degree[a]++;
		degree[b]++;
	}
	for (int i = 0; i < edges.size(); i++) {
		ii tmp = edges[i];
		a = tmp.first;
		b = tmp.second;
		for (int j = 0; j < n; j++) {
			if (g[a][j] == 0 || g[b][j] == 0)
				continue;
			rec = min(rec, degree[a] + degree[b] + degree[j]);
		}
	}
	if (rec == INF)
		cout << -1 << endl;
	else cout << rec - 6 << endl;
	return 0;
}
