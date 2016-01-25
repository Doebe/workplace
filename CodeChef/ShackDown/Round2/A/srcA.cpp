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
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

vector<vi> adj;
int T, N, maxDepth, vis[10010];
vi maxi, maxi2;
queue<int> q;

void dfs(int u, int depth, int v) {
	vis[u] = v;
	if (depth == maxDepth)
		maxi.push_back(u);
	if (depth > maxDepth) {
		maxDepth = depth;
		maxi.clear();
		maxi.push_back(u);
	}
	for (int i = 0; i < adj[u].size(); i++)
		if (vis[adj[u][i]] != v)
			dfs(adj[u][i], depth + 1, v);
}

void dfs2(int u, int depth, int v) {
	vis[u] = v;
	if (depth == maxDepth)
		maxi2.push_back(u);
	if (depth > maxDepth) {
		maxDepth = depth;
		maxi2.clear();
		maxi2.push_back(u);
	}
	for (int i = 0; i < adj[u].size(); i++)
		if (vis[adj[u][i]] != v)
			dfs2(adj[u][i], depth + 1, v);
}

int main() {
	cin >> T;
	while (T--) {
		cin >> N;
		adj.assign(N + 1, vi());
		for (int c = 1; c < N; c++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		maxi.clear();
		maxi2.clear();
		maxDepth = 0;

		MEM(vis, 0);
		int v = 1;
		dfs(1, 0, v);
		int mini = INF;

		vi visited(N+1, 0);
//		cout << N+1 << " " << maxi[0] << endl;
		for (int i = 0; i < maxi.size(); i++) {
			if (visited[maxi[i]])
				continue;
//			cout << "maxi[i]: " << maxi[i] << endl;
			visited[maxi[i]] = 1;
			dfs2(maxi[i], 0, ++v);
//			cout << maxi2.size() << endl;
			mini = min(mini, maxi2.size());
			if (mini == 1)
				break;
			for (int j = 0; j < maxi2.size(); j++)
				maxi.push_back(maxi2[j]);
			maxi2.clear();
		}
		if (mini == 1 && maxDepth > 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
