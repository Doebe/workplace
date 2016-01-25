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

int main(){
	int c, n, m, x, y, t;
	scanf("%d", &c);
	while (c--){
		scanf("%d %d", &n, &m);
		map<int, vii> adj;
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &x, &y, &t);
			adj[x].push_back(ii(y, t));
		}
		vi dist(n, INF); dist[0] = 0;
		for (int i = 0; i < n-1; i++)
			for (int u = 0; u < n; u++)
				for (int j = 0; j < (int)adj[u].size(); j++){
					ii v = adj[u][j];
					dist[v.first] = min(dist[v.first], dist[u] + v.second);
				}
		bool hasNegativeCycle = false;
		for (int u = 0; u < n; u++){
			for (int j = 0; j < (int)adj[u].size(); j++){
				ii v = adj[u][j];
				if (dist[v.first] > dist[u] + v.second){
					hasNegativeCycle = true;
					break;
				}
			}
			if (hasNegativeCycle)
				break;
		}
		if (hasNegativeCycle)
			printf("possible\n");
		else printf("not possible\n");
	}
}
