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
	double cost;
	Edge(int _u, int _v, int _c, double c) : u(_u),v(_v), cap(_c), cost(c){f=0;}

	int other(int w){if(w == u)return v;return u;}

	int resTo(int w){
		if(w == v)return cap - f;
		return f;
	}

	void addFlowTo(int w, int _f){
		if(w == v) f += _f;else f -= _f;
	}

	double getCost(int w){
		if(w == v)
			return cost;
		return -cost;
	}
};

void addEdge(int u, int v, int cap, double cost){
	Edge * e = new Edge(u,v,cap,cost);
	G[u].push_back(e);
	G[v].push_back(e);
}

typedef vector<Edge *> edgeList;
vector<edgeList> G;

int MAX_V = 102;
int res[MAX_V][MAX_V], V, aim, mf, f, s, t, n, m, a, b;
vi p;	// p stores the BFS spanning tree from s
edgeList P;

void augment(int v, int minEdge){	// traverse BFS spanning tree from s -> t
	if (v == s){
		f = minEdge; return;	// record minEdge in a global var f
	}else if (P[v] != NULL){
		augment(P[v]->other(v), min(minEdge, P[v]->resTo(v)));
		P[v]->addFlowTo(v, f), P[v]->addFlowTo(P[v]->other(v), f);
	}
}

// inside int main(): set up 'res', 's', and 't' with appropriate values
int main(){
	scanf("%d %d", &n, &m);
	V = n * 2 + 2;

	// Residual graph
	G.assign(V + 1,edgeList());

	// Initialize Source/Sink vertex
	s = n + m;
	t = n + m + 1;
	aim = 0;

	// Source to the i-th bank
	for (int i = 0; i < n; ++i){
		scanf("%d", &a);
		addEdge(s,i,a,0);
		addEdge(i,n+i,INF,0);
		addEdge(n+i,i,INF,0);
		aim += a;
	}

	// From the i-th cruiser to sink
	for (int i = 0; i < n; ++i){
		scanf("%d", &b);
		addEdge(n+i,t,b,0);
	}

	for (int i = 0; i < m; ++i){
		scanf("%d %d", &a, &b);
		addEdge(a,b,INF,0);
		addEdge(b,a,INF,0);
	}

	mf = 0;	// mf stands for max_flow
	while(1){	// O(VE^2) (actually O(V^3 E) Edmonds Karp's algorithm
		f = 0;	// run BFS
		vi dist(V+1, INF);
		dist[s] = 0;
		queue<int> q; q.push(s);
		P.assign(V+1, NULL);	// record the BFS spanning tree, from s to t
		while(!q.empty()){
			int u = q.front(); q.pop();
			if (u == t) break;	// immediately stop BFS if we already reach sink t
			for (int i = 0; i < G[u].size(); i++){	// this part is slow
				Edge * e = G[u][i];
				int v = e->other(u);
				if (e->resTo(v) > 0 && dist[v] == INF)
					dist[v] = dist[u] + 1, q.push(v), P[v] = e;
			}
		}
		augment(t, INF);	// find the min edge weight 'f' in this path, if any
		if (f == 0) break;	// we cannot send any more flow ('f' = 0), terminate
		mf += f;	// we can still send a flow, increase the max flow
	}
	if (mf != aim)
		printf("NO\n");
	else {
		printf("YES\n");

	}
}
