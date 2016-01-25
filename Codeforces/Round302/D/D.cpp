//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAX_INT = std::numeric_limits<int>::max();
//const int MIN_INT = std::numeric_limits<int>::min();
//const int INF = 1000000000;
//const int NEG_INF = -1000000000;
//
//#define max(a,b)(a>b?a:b)
//#define min(a,b)(a<b?a:b)
//#define MEM(arr,val)memset(arr,val, sizeof arr)
//#define PI acos(0)*2.0
//#define eps 1.0e-9
//#define are_equal(a,b)fabs(a-b)<eps
//#define LS(b)(b& (-b)) // Least significant bit
//#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians
//
//typedef long long ll;
//typedef pair<int,int> ii;
//typedef pair<int,char> ic;
//typedef pair<long,char> lc;
//typedef vector<int> vi;
//typedef vector<ii> vii;
//
//int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
//int lcm(int a,int b){return a*(b/gcd(a,b));}
//
//
//int adj[3002][3002], p1[3002], p2[3002];
//int n, m, a, b, s[2], t[2], l[2];
//vi dist;
//
//void bfs(int s, int t, int index){
//	queue<int> q; dist[s] = 0; q.push(s);
//	while (!q.empty()){
//		int u = q.front(); q.pop();
//		for (int i = 1; i <= n; i++){
//			if (adj[u][i] && dist[i] == INF){
//				dist[i] = dist[u] + 1;
//				if (!index) p1[i] = u;
//				else p2[i] = u;
//				q.push(i);
//			}
//		}
//	}
//}
//
//int main(){
//	scanf("%d %d", &n, &m);
//	MEM(adj, 0);
//	for (int i = 0; i < m; i++){
//		scanf("%d %d", &a, &b);
//		adj[a][b] = 1;
//		adj[b][a] = 1;
//	}
//	for (int i = 0; i < 2; i++)
//		scanf("%d %d %d", &s[i], &t[i], &l[i]);
//	dist.assign(n+1, INF);
//	bfs(s[0], t[0], 0);
//	dist.assign(n+1, INF);
//	bfs(s[1], t[1], 1);
//	vii path1, path2;
//	int l0 = 0, l1 = 0;
//	for (int i = t[0]; i != s[0]; i = p1[i]){
//		path1.push_back(ii(p1[i], i));
//		l0++;
//	}
//	cout << l0 << endl;
////	for (int i = 0; i <= n; i++)
////		cout << p2[i] << " ";
//	for (int i = t[1]; i != s[1]; i = p2[i]){
//		path2.push_back(ii(p2[i], i));
//		l1++;
//	}
//	cout << l1 << endl;
//	int overlap = 0;
//	for (int i = 0; i < path1.size(); i++){
//		for (int j = 0; j < path2.size(); j++){
//			if ((path1[i].first == path2[j].first && path1[i].second == path2[j].second) ||
//				 (path1[i].second == path2[j].first && path1[i].first == path2[j].second))
//				overlap++;
//		}
//	}
//	if (l0 <= l[0] && l1 <= l[1])
//		printf("%d\n", m - l0 - l1 + overlap);
//	else printf("-1\n");
//	return 0;
//}
//

#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

#define max(a,b)((a)>(b)?(a):(b))
#define min(a,b)((a)<(b)?(a):(b))
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI (acos(0)*2.0)
#define eps 1.0e-9
#define are_equal(a,b)fabs((a)-(b))<eps
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

//----------------------------------------------------------------------//
int V,E;

vector<vi> adj;
vi p,vis;

inline void add_edge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int dist[3010][3010];

void bfs(int s){

    queue<int> q;
    q.push(s);
    dist[s][s] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for (int i = 0,v; i < adj[u].size(); ++i) {
            v = adj[u][i];
            if(dist[s][v] == -1){
                dist[s][v] = dist[s][u] + 1;
                q.push(v);
            }
        }
    }
}

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void sol2(){
    cin >> V >> E;
    adj.assign(V+1,vi());
    int s1,s2,l1,t1,t2,l2,ans;

    for (int i = 0,u,v; i < E; ++i) {
        cin >> u >> v;
        u--,v--;
        add_edge(u,v);
    }
    MEM(dist,-1);
    for (int i = 0; i < V; ++i) {
        bfs(i);
    }


    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    s1--,t1--,s2--,t2--;

    int best = E+1;

    for (int iter = 0; iter < 2; ++iter) {
        swap(s1,t1);
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {

                int d1 = dist[s1][i] + dist[i][j] + dist[j][t1],
                    d2 = dist[s2][i] + dist[i][j] + dist[j][t2];

                if(d1 <= l1 && d2 <= l2){
                    best = min(best, d1 + d2 - dist[i][j]);
                }
            }
        }
    }


    if(dist[s1][t1] <= l1 && dist[s2][t2] <= l2)
        best = min(best,dist[s1][t1] + dist[s2][t2] );

    if(best > E)
        cout << "-1" << endl;
    else
        cout << E - best << endl;

}

int main(){
    sol2();
    return 0;
}
