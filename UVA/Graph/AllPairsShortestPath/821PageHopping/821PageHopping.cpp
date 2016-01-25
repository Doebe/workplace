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

int n, m, a, b, adj[102][102];

int main(){
	int c = 0;
	while (1){
		cin >> n >> m;
		if (!n && !m)
			break;
		int cnt = 0;
		int sum = 0;
		for (int i = 0; i < 102; i++)
			for (int j = 0; j < 102; j++){
				if (i == j)
					adj[i][j] = 0;
				else adj[i][j] = 1000;
			}
		adj[n][m] = 1;
		while (1){
			cin >> a >> b;
			if (!a && !b)
				break;
			adj[a][b] = 1;
		}

		for (int k = 0; k < 102; k++)
			for (int i = 1; i < 102; i++)
				for (int j = 1; j < 102; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		for (int i = 1; i < 102; i++)
			for (int j = 1; j < 102; j++)
				if (adj[i][j] != 1000 && adj[i][j] != 0){
					cnt++;
					sum += adj[i][j];
				}
		double avg = (double)sum / cnt;
		printf("Case %d: average length between pages = %.3lf clicks\n", ++c, avg);
	}
	return 0;
}
