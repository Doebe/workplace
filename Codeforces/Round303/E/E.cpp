#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const long long  INF = std::numeric_limits<long long>::max()/3;
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

vector<vii> adj;
vector<ii> edges;
int n, m, u, v, w, s;

int main(){
	scanf("%d %d", &n, &m);
	edges.push_back(ii(-1, -1));
	adj.assign(n+1, vii());
	for (int i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &w);
		edges.push_back(ii(u, v));
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
	}
	scanf("%d", &s);
	vii p(n+1, ii(-1, -1));
	vector<ll> dist(n+1, INF);
	dist[s] = 0;
	priority_queue<pair<ll, int> > pq;
	pq.push(pair<ll, int>(0, s));
	while(!pq.empty()){
		pair<ll, int> c = pq.top(); pq.pop();
		ll d = -c.first, a = c.second;
		if (dist[a] > d) continue;
		for (int i = 0; i < adj[a].size(); i++){
			ii b = adj[a][i];	//all outgoing edges from u
			if (dist[a] + b.second < dist[b.first] || (dist[a] + b.second == dist[b.first] && p[b.first].second > b.second)){
				dist[b.first] = dist[a] + b.second;	//relax operation
				pq.push(pair<ll, int>(-dist[b.first], b.first));
				p[b.first] = ii(a, b.second);
			}
//			else if (dist[a] + b.second == dist[b.first]){
//				if (p[b.first].second > d){
//					p[b.first] = ii(a, b.second);
//					cout << a << " " << b.first << endl;
//				}
//			}
		}
	}

	vi e;
	ll sum = 0;
	for (int i = 1; i < edges.size(); i++){
		u = edges[i].first, v = edges[i].second;
		if (p[u].first == v){
//			cout << u << " " << v << endl;
			e.push_back(i);
			sum += p[u].second;
		}else if (p[v].first == u){
//			cout << u << " " << v << endl;
			e.push_back(i);
			sum += p[v].second;
		}
	}
	cout << sum << endl;
	for (int i = 0; i < e.size(); i++){
		printf("%d ", e[i]);
	}
	return 0;
}
