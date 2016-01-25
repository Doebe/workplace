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
	int n, r, q, a, b, c = 0;
	while (scanf("%d", &n) == 1){
		if (n == 0)
			continue;
		vi val(n+1, -1);
		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		scanf("%d", &r);
		vector<vii> adj(n+1, vii());
		while(r--){
			scanf("%d %d", &a, &b);
			adj[a].push_back(ii(b, pow((val[b]-val[a]), 3)));
		}
		vi dist(n+1, INF);
		dist[1] = 0;
		for (int i = 0; i < n-1; i++)	// relax all E edges V-1 times
			for (int u = 1; u <= n; u++)	// these two loops = O(E), overall O(VE)
				for (int j = 0; j < (int)adj[u].size(); j++){
					ii v = adj[u][j];	// record SP spanning here if needed
					if (dist[v.first] > dist[u] + v.second && dist[u] != INF){
						dist[v.first] = dist[u] + v.second;
					}
				}

		// after running the O(VE) Bellman Ford's algorithm shown above
		for (int u = 1; u <= n; u++)	// one more pass to check
			for (int j = 0; j < (int)adj[u].size(); j++){
				ii v = adj[u][j];
				if (dist[v.first] > dist[u] + v.second && dist[u] != INF)
					dist[v.first] = -INF;
			}
		printf("Set #%d\n", ++c);
		scanf("%d", &q);
		while (q--){
			scanf("%d", &a);
			if (dist[a] >= 3 && dist[a] != INF)
				printf("%d\n", dist[a]);
			else printf("?\n");
		}
	}
}
