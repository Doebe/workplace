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

int n, V, s, t;
vector<vi> adj;
int main(){
	cin >> n;
	int num, vertex;
	vi emp;
	adj.assign(n, emp);
	for (int i = 0; i < n; i++){
		cin >> num;
		while (num--){
			cin >> vertex;
			adj[i].push_back(vertex);
		}
	}
//		for (int i = 0; i < m1.size(); i++){
//			for (int j = 0; j < m1.size(); j++)
//				cout << adj[i][j] << " ";
//			cout << endl;
//		}
	int t;
	cin >> t;
	while (t--){
		int s, w = 0, d = 0;
		cin >> s;
		vi dist(n, INF);
		vi boom(n, 0);
		boom[0] = 1;
		dist[s] = 0;
		queue<int> q; q.push(s);
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int j = 0; j < adj[u].size(); j++){
				int v = adj[u][j];
				if (dist[v] == INF){
					dist[v] = dist[u] + 1;
					boom[dist[v]]++;
					q.push(v);
				}
			}
		}
		if (boom[1] == 0)
			cout << 0 << endl;
		else {
			ii maxi(0, 0);
			for (int i = 1; i < n; i++)
				if (maxi.first < boom[i]){
					maxi.first = boom[i];
					maxi.second = i;
				}
			cout << maxi.first << " " << maxi.second << endl;
		}
	}
	return 0;
}
