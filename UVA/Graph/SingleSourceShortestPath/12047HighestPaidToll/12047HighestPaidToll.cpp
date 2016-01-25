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

int cs, n, m, s, t, p, u, v, c;
int main(){
	scanf("%d", &cs);
	while (cs--){
		scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
		vector<vii> adj1(n+1, vii());
		vector<vii> adj2(n+1, vii());
		for (int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &c);
			adj1[u].push_back(ii(v, c));
			adj2[v].push_back(ii(u, c));
		}
		int ans = -1;
		vi dist1(n+1, INF);
		dist1[s] = 0;
		vi dist2(n+1, INF);
		dist2[t] = 0;
		priority_queue<ii, vector<ii>, greater<ii> > pq1;
		priority_queue<ii, vector<ii>, greater<ii> > pq2;
		pq1.push(ii(0, s));
		pq2.push(ii(0, t));
		while (!pq1.empty()){
			ii front = pq1.top(); pq1.pop(); //greedy: get shortest unvisited vertex
			int d = front.first, u = front.second;
			if (d > dist1[u]) continue;	//important check
			for (int j = 0; j < (int)adj1[u].size(); j++){
				ii v = adj1[u][j];	//all outgoing edges from u
				if (dist1[u] + v.second < dist1[v.first]){
					dist1[v.first] = dist1[u] + v.second;	//relax operation
					pq1.push(ii(dist1[v.first], v.first));
				}
			}
		}	//this variant can cause duplicate items in the priority queue
		while (!pq2.empty()){
			ii front = pq2.top(); pq2.pop(); //greedy: get shortest unvisited vertex
			int d = front.first, u = front.second;
//			cout << "d " << d << " u " << u << endl;
			if (d > dist2[u]) continue;	//important check
			for (int j = 0; j < (int)adj2[u].size(); j++){
				ii v = adj2[u][j];	//all outgoing edges from u
				if (dist2[u] + v.second < dist2[v.first]){
					dist2[v.first] = dist2[u] + v.second;	//relax operation
					pq2.push(ii(dist2[v.first], v.first));
				}
			}
		}	//this variant can cause duplicate items in the priority queue
		for (int i = 1; i < adj1.size(); i++){
			for (int j = 0; j < adj1[i].size(); j++){
				if (dist1[i] + adj1[i][j].second + dist2[adj1[i][j].first] <= p)
					ans = max(ans, adj1[i][j].second);
			}
		}
		printf("%d\n", ans);
	}
}
