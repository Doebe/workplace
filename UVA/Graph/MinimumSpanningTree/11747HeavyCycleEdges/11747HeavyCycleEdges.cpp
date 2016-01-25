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

int m, n, x, y, z, mst_cost;
map<int, vii> adj;
vi taken;
priority_queue<pair<int, ii> > pq;

void process(int vtx){
	taken[vtx] = 1;
	for (int j = 0; j < (int)adj[vtx].size(); j++){
		ii v = adj[vtx][j];
		if (!taken[v.first]) pq.push(make_pair(-v.second, ii(vtx, v.first)));
	}
}

int main(){
	while (cin >> m >> n){
		if (m == 0)
			break;
		for (int i = 0; i < m; i++){
			vii l;
			adj[i] = l;
		}
		int total = 0;
		for (int i = 0; i < n; i++){
			cin >> x >> y >> z;
			total += z;
			adj[x].push_back(ii(y, z));
			adj[y].push_back(ii(x, z));
		}
//		for (int i = 0; i < m; i++){
//			cout << i << ": ";
//			for (int j = 0; j < adj[i].size();j++){
//				cout << adj[i][j].first << "," << adj[i][j].second << " ";
//			}
//			cout << endl;
//		}
		taken.assign(m, 0);
		vi edges;
		for (int i = 0; i < m; i++){
			if (!taken[i]) process(i);
			while(!pq.empty()){
				pair<int, ii> front = pq.top(); pq.pop();
				int w = -front.first;
				int v = front.second.second;
				if (!taken[v])
					process(v);
				else (edges.push_back(w));
			}
		}
		sort(edges.begin(), edges.end());
		if (edges.size() == 0)
			cout << "forest" << endl;
		else {
			for (int i = 0; i < edges.size() - 1; i++)
				cout << edges[i] << " ";
			cout << edges[edges.size() - 1] << endl;
		}
	}
	return 0;
}
