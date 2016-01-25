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

int main(){
	int n, l, a, b, color[201];
	map<int, vi> adj;
	while (cin >> n){
		if (n == 0)
			break;
		MEM(color, -1);
		adj.clear();
		cin >> l;
		while (l--){
			cin >> a >> b;
			adj[a].push_back(b);
		}
		queue<int> q;
		q.push(0);
		color[0] = 0;
		bool isBipartite = true;
		while (!q.empty()){
			int cur = q.front(); q.pop();
			for (int i = 0; i < adj[cur].size(); i++){
				int x = adj[cur][i];
				if (color[x] == -1){
					color[x] = 1 - color[cur];
					q.push(x);
				} else if (color[x] == color[cur]){
					isBipartite = false;
					break;
				}
			}
		}
		if (isBipartite)
			cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}
	return 0;
}
