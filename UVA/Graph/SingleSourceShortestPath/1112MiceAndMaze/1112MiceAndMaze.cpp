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

int c, n, s, t, m;
map<int, vi> adj;
int main(){
	int cs = 0;
	scanf("%d", &c);
	while (c--){
		scanf("%d %d %d %d", &n, &s, &t, &m);
		vi dist(n + 1, INF);
		dist[s] = 0;
		map<int, vii> adj;
		int a, b, w;
		while (m--){
			scanf("%d %d %d", &a, &b, &w);
			adj[b].push_back(ii(a, w));
		}
		priority_queue<ii, vector<ii>, greater<ii> > pq;
		pq.push(ii(0, s));
		while (!pq.empty()){
			ii front = pq.top(); pq.pop(); //greedy: get shortest unvisited vertex
			int d = front.first, u = front.second;
			if (d > dist[u]) continue;	//important check
			for (int j = 0; j < (int)adj[u].size(); j++){
				ii v = adj[u][j];	//all outgoing edges from u
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;	//relax operation
					pq.push(ii(dist[v.first], v.first));
				}
			}
		}	//this variant can cause duplicate items in the priority queue
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (dist[i] <= t)
				cnt++;
		if (++cs > 1)
			printf("\n");
		printf("%d\n", cnt);
	}
}
