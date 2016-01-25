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
typedef vector<long> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

map<long, vi> adj;
vi rank1;
map<long, int> v;

void dfs(long x) {
//	cout << x << endl;
	v[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!v[adj[x][i]])
			dfs(adj[x][i]);
	}
	rank1.push_back(x);
}

int lis(vi s)
{
	vi M(s.size(), 0);
	int L = 0;
	for(int i = 0 ; i < s.size( ) ; i++){

		int j = lower_bound(M.begin(), M.begin()+L, s[i]) - M.begin();
		M[j] = s[i];
		if(j == L)L++;
	}
	return L;
}
int main(){
	int n, m, d;
	ll a, b, c;
	cin >> n >> m >> d;
	v.clear();
	while (m--) {
		cin >> a >> b;
		if (!adj.count(a)) {
			adj[a] = vi();
			v[a] = 0;
		}
		if (!adj.count(b)) {
			adj[b] = vi();
			v[b] = 0;
		}
		adj[a].push_back(b);
	}
	v.clear();
	for (map<long, vi>::iterator it = adj.begin(); it != adj.end(); it++) {
		if (!v[it->first])
			dfs(it->first);
	}
	reverse(rank1.begin(), rank1.end());
	map<long, long> db;
	vi visited(n, 0);
	for (int i = 0; i < rank1.size(); i++)
		db[rank1[i]] = i;

	vi wrong;
	int cnt = 0;
	int dup = 0;
	while (n--) {
		cin >> c;
		if (!db.count(c)) {
			cnt += 2;
		}
		else {
			if (visited[db[c]])
				dup++;
			wrong.push_back(c);
			visited[db[c]] = 1;
		}
	}
	vi wrank;
	for (int i = 0; i < wrong.size(); i++) {
		wrank.push_back(db[wrong[i]]);
	}
	int l = lis(wrank);
	cnt += (wrank.size()-l) * 2;
	cout << cnt << endl;

	return 0;
}
