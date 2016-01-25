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

vector<vii> adj;
vector<pair<int, ii> > path;
map<int, ii> m1;
map<ii, int> m2;

int main(){
	int n, m, u, v, w, s;
	cin >> n >> m;
	vii emp;
	adj.assign(n+1, emp);
	for (int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
		adj[v].push_back(ii(u, w));
		m1[i] = ii(u, v);
		m2[ii(u, v)] = i;
	}
	cin >> s;
	vi dist(n+1, INF);
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0, s));
	while(!pq.empty()){
		ii front = pq.top();
		pq.pop();
		int d = front.first, x = front.second;
		if (d > dist[x]) continue;
		for (int i = 0; i < (int)adj[x].size(); i++){
			ii y = adj[x][i];
			if (dist[x] + y.second <= dist[y.first]){
				dist[y.first] = dist[x] + y.second;
				for (vector<pair<int, ii> >::iterator it = path.begin(); it != path.end(); it++){
					pair<int, ii> cur = *it;
					if ((cur.second.first == y.second || cur.second.second == y.second) && cur.first > y.second){
						path.erase(it);
						break;
					}
				}
				path.push_back(make_pair(y.second, ii(x, y.first)));
				pq.push(ii(dist[y.first], y.first));
			}
		}
	}
	int sum = 0;
	vi numbers;
	for (int i = 0; i < path.size(); i++){
		pair<int, ii> cur = path[i];
		int num = -1;
		if (m2.count(cur.second))
			num = m2[cur.second];
		else num = m2[ii(cur.second.second, cur.second.first)];
		numbers.push_back(num);
		sum += cur.first;
	}
	cout << sum << endl;
	for (int i = 0; i < numbers.size() - 1; i++){
		cout << numbers[i] << " ";
	}
	cout << numbers[numbers.size() - 1] << endl;
	return 0;
}
