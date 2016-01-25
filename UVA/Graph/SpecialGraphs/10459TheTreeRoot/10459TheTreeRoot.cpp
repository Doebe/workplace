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

map<int, vi> adj;
int N, maxDepth, vis[5010], dist[5010], parents[5010];
vi mini, maxi, maxi2, temp;
queue<int> q;

void dfs(int u, int depth){
	vis[u] = 1;
	if (depth == maxDepth) maxi.push_back(u);
	if (depth > maxDepth){
		maxDepth = depth;
		maxi.clear();
		maxi.push_back(u);
	}
	for (int i = 0; i < adj[u].size(); i++)
		if (!vis[adj[u][i]])
			dfs(adj[u][i], depth+1);
}

void dfs2(int u, int depth){
	vis[u] = 1;
	if (depth == maxDepth)
		maxi2.push_back(u);
	if (depth > maxDepth){
		maxDepth = depth;
		maxi2.clear();
		maxi2.push_back(u);
	}
	for (int i = 0; i < adj[u].size(); i++)
		if (!vis[adj[u][i]])
			dfs2(adj[u][i], depth+1);
}

void cutTree(int n){
	mini.clear();
	if (temp.size() == 0){
		for (int i = 1; i <= N; i++)
			if (parents[i] == 1){
				q.push(i);
				mini.push_back(i);
			}
	}
	else for (int i = 0; i < temp.size(); i++)
		if (parents[temp[i]] == 1){
			q.push(temp[i]);
			mini.push_back(temp[i]);
		}
	temp.clear();
	int dif = n - mini.size();

	if (dif <= 2){
		mini.clear();
		while (!q.empty()){
			int u = q.front();
			q.pop();
			parents[u]--;
		}
		for (int i = 1; i <= N; i++)
			if (parents[i] > 0)
				mini.push_back(i);
		return ;
	}

	while (!q.empty()){
		int u = q.front();
		q.pop();
		parents[u]--;

		for (int i = 0; i < adj[u].size(); i++){
			if (--parents[adj[u][i]] == 1)
				temp.push_back(adj[u][i]);
		}
	}
	cutTree(dif);
}

int main(){
	while (cin >> N){
		adj.clear();
		MEM(dist, 0);
		MEM(parents, 0);
		for (int n = 1; n <= N; n++){
			int a, b;
			cin >> a;
			while (a--){
				cin >> b;
				adj[n].push_back(b);
				parents[n]++;
			}
		}

		mini.clear();
		maxi.clear();
		maxi2.clear();
		temp.clear();
		maxDepth = 0;

		MEM(vis, 0);
		for (int i = 1; i <= N; i++)
			if (vis[i] == 0 && adj[i].size() > 0)
				dfs(1, 0);
		MEM(vis, 0);
		dfs2(maxi[0], 0);
		cutTree(N);

		for (int i = 0; i < maxi2.size(); i++)
			if (find(maxi.begin(), maxi.end(), maxi2[i]) == maxi.end())
				maxi.push_back(maxi2[i]);

		sort(mini.begin(), mini.end());
		sort(maxi.begin(), maxi.end());
		cout << "Best Roots  :";
		for (int i = 0; i < mini.size(); i++)
			cout << " " << mini[i];
		cout << endl;
		cout << "Worst Roots :";
		for (int i = 0; i < maxi.size(); i++)
			cout << " " << maxi[i];
		cout << endl;
	}
	return 0;
}
