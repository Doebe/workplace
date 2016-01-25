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

int N, p[22][22][22];
double adj[22][22][22];

int main(){
	while (scanf("%d\n", &N) == 1){
		int cnt = 0;
		MEM(adj, 0);

		for (int n = 1; n <= N; n++){
			string line;
			stringstream ss;
			getline(cin, line);
			ss.str(line);
			double cur;
			for (int m = 1; m <= N; m++){
				if (m == n)
					adj[1][n][m] = 1;
				else
					ss >> adj[1][n][m];
				p[1][n][m] = n;
			}
		}

		for (int step = 2; step <= N; step++)
			for (int k = 1; k <= N; k++)
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++){
						double temp = adj[step-1][i][k] * adj[1][k][j];
						if (adj[step][i][j] < temp){
							adj[step][i][j] = temp;
							p[step][i][j] = k;
						}
					}
		int step, target = -1;
		for (step = 2; step <= N; step++){
			for (int i = 1; i <= N; i++){
				if (adj[step][i][i] > 1.01){
					target = i;
					break;
				}
			}
			if (target != -1)
				break;
		}
		if (target==-1)
			cout << "no arbitrage sequence exists" << endl;
		else {
			int outputSeq[22];
			int index = 0;
			int cur = target;
			outputSeq[index++] = cur;
			for (int s = step; s >= 1; s--){
				cur = p[s][target][cur];
				outputSeq[index++] = cur;
			}
			for (int i = index-1; i > 0; i--)
				cout << outputSeq[i] << " ";
			cout << outputSeq[0] << endl;
		}
	}
	return 0;
}
