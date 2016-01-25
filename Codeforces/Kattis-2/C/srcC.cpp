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

int V, E, u, v, w, s, t;
vector<vii> adj;
vii dist;

//void dfs(int x, int d) {
//	for (int i = 0; i < adj[x].size(); i++) {
//		int tv = adj[x][i].first;
//		int tw = adj[x][i].second;
//		if (tw+d < dist[tv].first) {
//			dist[tv].first = tw+d;
//			dist[tv].second = dist[x].second;
//			dfs(tv, tw+d);
//		} else if (tw+d == dist[tv].first) {
//			dist[tv].second += dist[x].second;
//			dfs(tv, tw+d);
//		}
//	}
//}

int main(){
	cin >> V >> E;
	adj.assign(V, vii());
	dist.assign(V, ii(INF,0));
	while (E--) {
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
	}
	cin >> s >> t;
	dist[s] = ii(0, 1);
//	dfs(s, 0);
//	cout << dist[t].second << endl;


	priority_queue<ii> pq;



	pq.push(ii(0, s));
	int cnt = 0;
	while (!pq.empty()) {
		ii cur = pq.top(); pq.pop();
		int curw = -cur.first;
		int curu = cur.second;
		if (curw > dist[curu].first)
			continue;
		if (curu == t)
			break;
		for (int i = 0; i < adj[curu].size(); i++) {
			int curv = adj[curu][i].first;
//			cout << curu << " " << curw << " " << curv << endl;
			if (dist[curv].first == curw + adj[curu][i].second) {
				dist[curv].second += dist[curu].second;
//				cout << "debug1: " << curv << " " << curu << " " << dist[curv].second << endl;
//				pq.push(ii(-dist[curv].first, curv));
			} else if (dist[curv].first > curw+adj[curu][i].second) {
				dist[curv].first = curw + adj[curu][i].second;
				dist[curv].second = dist[curu].second;
//				cout << "debug2: " << curv << " " << curu << " " << dist[curv].second << endl;
				pq.push(ii(-dist[curv].first, curv));
			}
		}
	}
//	for (int i = 0; i < V; i++)
//		cout << dist[i].first << " " << dist[i].second << endl;
	cout << dist[t].second << endl;
	return 0;
}
