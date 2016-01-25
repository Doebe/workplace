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
	int n, v, e, a, b, color[201];
	map<int, vi> adj;
	cin >> n;
	while (n--){
		cin >> v >> e;
		MEM(color, -1);
		adj.clear();
		while (e--){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool isBipartite = true;
		queue<int> q;
		int cnt = 0;
		for (int i = 0; i < v; i++){
			int cnt0 = 0, cnt1 = 0;
			if (color[i] == -1){
				color[i] = 0;
				cnt0++;
				q.push(i);
				while (!q.empty()){
					int cur = q.front(); q.pop();
					for (int j = 0; j < adj[cur].size(); j++){
						int x = adj[cur][j];
						if (color[x] == -1){
							color[x] = 1 - color[cur];
//							cout << x << " " << color[x] << endl;
							if (color[x] == 0)
								cnt0++;
							else cnt1++;
							q.push(x);
						} else if (color[x] == color[cur]){
							isBipartite = false;
							break;
						}
					}
				}
				if (cnt1 == 0)
					cnt1 = 1;
				cnt += min(cnt0, cnt1);
//				cout << "cnt: " << cnt << endl;
			}
		}
		if (isBipartite)
			cout << cnt << endl;
		else cout << -1 << endl;
	}
	return 0;
}
