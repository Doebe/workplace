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

int T, N, R, adj[102][102];

int main(){
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> N >> R;
		for (int i = 0; i < 102; i++)
			for (int j = 0; j < 102; j++){
				if (i == j)
					adj[i][j] = 0;
				else adj[i][j] = 1000;
			}
		int a, b;
		while (R--){
			cin >> a >> b;
			adj[a][b] = 1;
			adj[b][a] = 1;
		}

		for (int k = 0; k < 102; k++)
			for (int i = 0; i < 102; i++)
				for (int j = 0; j < 102; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		cin >> a >> b;
		int m = 0;
		for (int i = 0; i < 102; i++)
			if (adj[a][i] != 1000 && adj[i][b] != 1000){
				m = max(m, adj[a][i] + adj[i][b]);
			}
		cout << "Case " <<  t << ": " << m << endl;
	}
	return 0;
}
