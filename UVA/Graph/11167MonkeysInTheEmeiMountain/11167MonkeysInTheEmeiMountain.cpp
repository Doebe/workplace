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

class Edge{
public :
	int u,v,cap,f;
	Edge(int _u, int _v, int _c) : u(_u),v(_v), cap(_c){f=0;}

	int other(int w){if(w == u)return v;return u;}

	int resTo(int w){
		if(w == v)return cap - f;
		return f;
	}

	void addFlowTo(int w, int _f){
		if(w == v) f += _f;else f -= _f;
	}
};

int V, n, m, c, a, b, s, t, mf, total;
typedef vector<Edge *> edgeList;
vector<edgeList> G;
edgeList P;

void addEdge(int u, int v, int cap){
	Edge * e = new Edge(u,v,cap);
	if (find(G[u].begin(), G[u].end(), e) == G[u].end()){
		G[u].push_back(e);
		G[v].push_back(e);
	}
}

//void augment(int v, int minEdge){
//	if (v == s) {
//		f = minEdge;
//		return;
//	}
//	else if (P[v] != NULL){
////		augment(P[v]->cap, min(minEdge, P[v]->cap));
//		int u = P[v]->other(v);
//		G[u][v]->cap -= f;
////		G[v][u]->cap += f;
//	}
//}

int main(){
	while (cin >> n){
		if (n == 0)
			break;
		cin >> m;
		V = 50001 + n + 2;
		s = 0; t = 50001 + n;
		mf = total = 0;
		G.assign(V,edgeList());
		for (int i = 0; i < n; i++){
			cin >> c >> a >> b;
			for (int j = a; j < b; j++){
				addEdge(j, 50001 + i, 1);
				addEdge(s, j, m);
			}
			addEdge(50001 + i, t, c);
		}

		while (1) {
			vi dist(V, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			P.assign(V, NULL);
			while (!q.empty()){
				int u = q.front(); q.pop();
				cout << "u: " << u <<endl;
				if (u == t)
					break;
				for (int j = 0; j < G[u].size(); j++){
					Edge * e = G[u][j];
					int v = e->other(u);
					if (e->cap > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1, q.push(v), P[v] = e;
					}
				}
			}

			int min_res = INF;
			for(int v = t; v!= s;v = P[v]->other(v)){
				min_res = min(min_res,  P[v]->cap);
			}
			cout << "f: " << min_res << endl;
//			// Add flow to the residual graph
			for(int v = t; v!= s;v = P[v]->other(v)){
				G[P[v]->other(v)][v]->cap -= min_res;
			}

			if (min_res == 0)
				break;
			mf += min_res;
		}
		cout << mf << endl;
	}

	return 0;
}
