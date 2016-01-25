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

int t, f, n;
vi dist, visit;
map<int, vii> adj;

vi dijkstra(int s){
	vi d(n+1, INF);
	d[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while (!pq.empty()){
		ii front = pq.top(); pq.pop(); //greedy: get shortest unvisited vertex
		int w = front.first, u = front.second;
		if (w > d[u]) continue;	//important check
		for (int j = 0; j < (int)adj[u].size(); j++){
			ii v = adj[u][j];	//all outgoing edges from u
			if (d[u] + v.second < d[v.first]){
				d[v.first] = d[u] + v.second;	//relax operation
				pq.push(ii(d[v.first], v.first));
			}
		}
	}
	return d;
}

int main(){
	cin >> t;
	int c = 0, firestation;
	while (t--){
		cin >> f >> n;
		dist.assign(n+1, INF);
		visit.assign(n+1, 0);
		while (f--){
			cin >> firestation;
			dist[firestation] = 0;
		}
		int a, b, w;
		adj.clear();
		vii emp;
		for (int i = 0; i <= n; i++)
			adj[i] = emp;
		string line;
		getline(cin, line);
		while (getline(cin, line)){
			if (line == "")
				break;
			stringstream ss;
			ss.str(line);
			ss >> a >> b >> w;
			adj[a].push_back(ii(b, w));
			adj[b].push_back(ii(a, w));
		}
		for (int i = 1; i <= n; i++){
			if (dist[i] == 0){
				vi temp = dijkstra(i);
				for (int j = 1; j <= n; j++)
					dist[j] = min(dist[j], temp[j]);
			}
		}
//		for (int i = 1; i <=n ;i++)
//			cout << dist[i] << " ";
//		cout << endl;

		ii mini(INF, firestation);
		for (int i = 1; i <= n; i++){
			int maxi = 0;
			if (dist[i] != 0){
				vi temp = dijkstra(i);
				for (int j = 1; j <= n; j++){
					temp[j] = min(dist[j], temp[j]);
					maxi = max(maxi, temp[j]);
				}
//				for (int j = 1; j <= n; j++){
//					cout << temp[j] << " ";
//				}
//				cout << endl;
				if (mini.first > maxi){
					mini.first = maxi;
					mini.second = i;
//					cout << mini.first << " " << mini.second << endl;
				}
			}
		}
		if (++c > 1)
			cout << endl;
		cout << mini.second << endl;
	}
//	int i = 500;
//	while (i > 1){
//		printf("1 %d 10\n", i--);
//	}
	return 0;
}
