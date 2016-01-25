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

typedef vector<Edge *> edgeList;
vector<edgeList> G;

void addEdge(int u, int v, double cost){
	Edge * e = new Edge(u,v,1,cost);
	G[u].push_back(e);
	G[v].push_back(e);
}


int MAX_V = INF;
int res[MAX_V][MAX_V], mf, f, s, t;
vi p;	// p stores the BFS spanning tree from s

void augment(int v, int minEdge){	// traverse BFS spanning tree from s -> t
	if (v == s){
		f = minEdge; return;	// record minEdge in a global var f
	}else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

// inside int main(): set up 'res', 's', and 't' with appropriate values
int main(){
	mf = 0;	// mf stands for max_flow
	while(1){	// O(VE^2) (actually O(V^3 E) Edmonds Karp's algorithm
		f = 0;	// run BFS
		vi dist(MAX_V, INF);
		dist[s] = 0;
		queue<int> q; q.push(s);
		p.assign(MAX_V, -1);	// record the BFS spanning tree, from s to t
		while(!q.empty()){
			int u = q.front(); q.pop();
			if (u == t) break;	// immediately stop BFS if we already reach sink t
			for (int v = 0; v < MAX_V; v++)	// this part is slow
				if (res[u][v] > 0 && dist[v] == INF)
					dist[v] = dist[u] + 1, q.push(v), p[v] = u;
		}
		augment(t, INF);	// find the min edge weight 'f' in this path, if any
		if (f == 0) break;	// we cannot send any more flow ('f' = 0), terminate
		mf += f;	// we can still send a flow, increase the max flow
	}
}
