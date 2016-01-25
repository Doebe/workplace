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

int vis[100010];
ii  all[100010];

void bfs(int a, int i) {
	queue<ii> q;
	q.push(ii(a, 0));
	while (!q.empty()) {
		ii cur = q.front(); q.pop();
		if (vis[cur.first] == i) continue;
		vis[cur.first] = i;
		all[cur.first].first += cur.second;
		all[cur.first].second++;
		int tmp1 = cur.first / 2;
		int tmp2 = cur.first * 2;
		if (vis[tmp1] != i)
			q.push(ii(tmp1, cur.second+1));
		if (tmp2 < 100010 && vis[tmp2] != i)
			q.push(ii(tmp2, cur.second+1));
	}
}

int main(){
	int n, a;
	cin >> n;
	for (int i = 0; i < 100010; i++)
		all[i] = ii(0, 0);
	MEM(vis, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a;
		bfs(a, i);
	}
	int mn = INF;
	for (int i = 0; i < 100010; i++)
		if (all[i].second == n)
			mn = min(mn, all[i].first);
	printf("%d\n", mn);
	return 0;
}
