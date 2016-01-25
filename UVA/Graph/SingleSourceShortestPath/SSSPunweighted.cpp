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

int V, s, t;
vector<vii> adj;
int main(){
	vi dist(V, INF);
	dist[s] = 0;
	queue<int> q; q.push(s);
	vi p;	// addition: the predecessor/parent vector
	while (!q.empty()){
		int u = q.front(); q.pop();
		for (int j = 0; j < (int)adj[u].size(); j++){
			ii v = adj[u][j];	//all outgoing edges from u
			if (dist[v.first] == INF){
				dist[v.first] = dist[u] + 1;
				p[v.first] = u;	//addition: the parent of vertex v.first is u
				q.push(v.first);
			}
		}
	}
}
