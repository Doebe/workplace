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

vector<vi> G;
vi vis;

int bfs(int a, int b){
	queue<int> q;
	q.push(a);
	vis.assign(21,-1);
	vis[a] = 0;
	while(!q.empty()){

		int u = q.front();	q.pop();

		if(u == b)return vis[u];

		for (int i = 0; i < G[u].size(); ++i) {
			int v = G[u][i];

			if(vis[v] == -1){
				q.push(v);
				vis[v] = vis[u] + 1;
			}
		}
	}
	return -1;
}

int main(){
	int Test = 1;
	while(1){
		G.assign(21, vi());
		for (int i = 1; i < 20; ++i) {
			int t;
			if(scanf("%d", &t) != 1)return 0;
			for (int j = 0,v; j < t; ++j) {
				scanf("%d", &v);
//				printf("adding edge : %d %d\n",i,v);
				G[i].push_back(v);
				G[v].push_back(i);
			}
		}

		int q;scanf("%d", &q);

		printf("Test Set #%d\n",Test++);
		for (int i = 0; i < q; ++i) {
			int a, b;
			scanf("%d %d ", &a, &b);
			int ans = bfs(a,b);
//			printf("%*d\n",2,a);
			printf("%*d to %*d:%*d\n",2,a,2,b,2,ans);
		}
		printf("\n");
	}

}
