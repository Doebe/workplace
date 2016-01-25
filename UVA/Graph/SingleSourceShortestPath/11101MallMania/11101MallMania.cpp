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

int p1, p2, a, b, adj[2010][2010], dist[2010][2010], mini;
int r[] = {-1, 0, 1, 0}, c[] = {0, -1, 0, 1};
queue<ii> q;

bool valid(ii cur){
	return cur.first >= 0 && cur.first <= 2000 && cur.second >= 0 && cur.second <= 2000;
}

int bfs(){
	while (!q.empty()){
		ii u = q.front(); q.pop();
		for (int i = 0; i < 4; i++){
			ii v(u.first + r[i], u.second + c[i]);	//all outgoing edges from u
			if (valid(v) && dist[v.first][v.second] == -1){
				dist[v.first][v.second] = dist[u.first][u.second] + 1;
				if (adj[u.first][u.second] == 2)
					return(dist[u.first][u.second]);
				q.push(v);
			}
		}
	}
}

int main(){
	while (cin >> p1){
		if (p1 == 0)
			break;
		q = queue<ii>();
		MEM(dist, -1);
		MEM(adj, 0);
		for (int i = 0; i < p1; i++){
			cin >> a >> b;
			adj[a][b] = 1;
			q.push(ii(a, b));
			dist[a][b] = 0;
		}
		cin >> p2;
		for (int i = 0; i < p2; i++){
			cin >> a >> b;
			adj[a][b] = 2;
		}
		cout << bfs() << endl;
	}
}
