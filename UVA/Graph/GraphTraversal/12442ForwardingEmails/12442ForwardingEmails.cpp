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

int T, N, u, v, vst[50010], adj[50010], num[50010], xpl[50010], cnt;
ii m;

void dfs(int a){
	cnt++;
	xpl[a] = 1;
	int count = 1; int b = adj[a];
	if (vst[b])
		num[a] = num[b] + count;
	else if (xpl[b]){
		int next = a;
		while ((next = adj[next]) != a){
			count++;
		}
		for (int i = 0; i < count; i++){
			num[next] = count;
			next = adj[next];
		}
	} else {
		dfs(b);
		if (num[a] == 0)
			num[a] = num[b] + count;
	}
	if (m.first < num[a]){
		m.first = num[a];
		m.second = a;
	}else if (m.first == num[a]){
		m.second = min(m.second, a);
	}
	vst[a] = 1;
}
//
//void rec(int i){
//	if (i <= 260000) rec(++i);
//	return;
//}

int main(){
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> N;
		cnt = 0;
		m = ii(0, 0); // m means max, first is count, second is vertex.
		MEM(adj, 0); MEM(vst, 0); MEM(xpl, 0); MEM(num, 0);
		for (int j = 0; j < N; j++){
			cin >> u >> v;
			adj[u] = v;
		}
		for (int j = 1; j <= N; j++)
			if (!vst[j])
				dfs(j);
		cout << "Case " << i + 1 << ": " << m.second << endl;
		cout << cnt << endl;
	}
//	rec(0);
//	cout << 1 << endl;
//	return 0;
}
