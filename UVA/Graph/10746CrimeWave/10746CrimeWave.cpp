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

int V = 42, mf, f, n, m, s = 0, t = 41;
edgeList P;

void addEdge(int u, int v, double cost){
	Edge * e = new Edge(u,v,1,cost);
	G[u].push_back(e);
	G[v].push_back(e);
}

bool bellmanFord(){
	vi dist(V, INF);
	dist[s] = 0;
	P.assign(V, NULL);
	for (int i = 0; i < V - 1; i++)
		for (int u = 0; u < V; u++)
			for (int j = 0; j < G[u].size(); j++){
				Edge * e = G[u][j];
				int v = e->other(u);
				// Relax edge
				if(e->resTo(v) > 0 && dist[v] > dist[u] + e->getCost(v)){
					dist[v] = dist[u] + e->getCost(v);
					// Parent of v is in edge 'e'
					P[v] = e;
				}
			}
	return P[t] != NULL;
}

int main(){

	while(scanf("%d %d", &n, &m) == 2 && (n || m)){
		// Total number of vertices(Including Source and Sink)
		V = n + m + 2;

		// Residual graph
		G.assign(V + 1,edgeList());
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j){
				double cost;scanf("%lf", &cost);
				addEdge(i,n+j,cost);
			}

		// Initialize Source/Sink vertex
		s = n + m;
		t = n + m + 1;

		// Source to the i-th bank
		for (int i = 0; i < n; ++i)
			addEdge(s,i,0.0);

		// From the i-th cruiser to sink
		for (int i = 0; i < m; ++i)
			addEdge(n+i,t,0.0);


		/**
		 * While has augmenting path
		 * the bellmanFord method returns true if there is an augmenting path
		 * and it stores the path in the global vector 'P'
		 */
		while(bellmanFord()){
			double min_res = 1;
			// Find the minimum residual edge and calculate the cost of the path
			for(int v = t; v!= s;v = P[v]->other(v)){
				min_res = min(min_res,  P[v]->resTo(v));
			}

			// Add flow to the residual graph
			for(int v = t; v!= s;v = P[v]->other(v)){
				P[v]->addFlowTo(v,min_res);
			}
		}

		double cost = 0.0;

		// Find all the matches and add up the cost
		for (int u = 0; u < n; ++u) {
			for (int j = 0; j < G[u].size(); ++j) {
				int v = G[u][j]->other(u);
				// If the residual from u to v is zero then
				// this u and v are matched
				if(G[u][j]->resTo(v) == 0){
					cost += G[u][j]->getCost(v);
				}
			}
		}

		printf("%.2lf\n", cost/n);

	}

	return 0;
}

