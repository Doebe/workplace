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

int r[] = {-1, 0, 1, 0}, c[] = {0, -1, 0, 1};
map<int, vi> adj;
int main(){
	int t, n, m;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &m);
		int adj[n][m], dist[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++){
				scanf("%d", &adj[i][j]);
				dist[i][j] = INF;
			}
		dist[0][0] = adj[0][0];
		priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
		pq.push(make_pair(0, ii(0, 0)));
		bool found = false;
		while (!pq.empty()){
			pair<int, ii> front = pq.top(); pq.pop(); //greedy: get shortest unvisited vertex
			int d = front.first; ii u = front.second;
			if (d > dist[u.first][u.second]) continue;	//important check
			for (int i = 0; i < 4; i++){
				int x = u.first + r[i];
				int y = u.second + c[i];
				if (x >= 0 && x < n && y >= 0 && y < m){
					int w = adj[x][y];	//all outgoing edges from u
					if (dist[u.first][u.second] + w < dist[x][y]){
						dist[x][y] = dist[u.first][u.second] + w;	//relax operation
						pq.push(make_pair(dist[x][y], ii(x, y)));
					}
					if (x == n-1 && y == m-1){
						found = true;
						break;
					}
				}
			}
			if (found)
				break;
		}
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < m; j++)
//				cout << dist[i][j] << " ";
//			cout << endl;
//		}
		printf("%d\n", dist[n-1][m-1]);
	}

}
