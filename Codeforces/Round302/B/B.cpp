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
	int n, k;
	scanf("%d %d", &n, &k);
	if (k > (n*n+1)/2)
		printf("NO\n");
	else{
		printf("YES\n");
		int adj[n][n];
		MEM(adj, -1);
		for (int i = 0; i < n; i++){
			if (k <= 0)
				break;
			for (int j = 0; j < n; j++){
				if (adj[i][j] == -1){
					adj[i][j] = 1;
					if (i+1 < n)
						adj[i+1][j] = 0;
					if (j+1 < n)
						adj[i][j+1] = 0;
					k--;
					if (k <= 0) break;
				}else if (adj[i][j] == 0)
					continue;
			}
		}
		for (int i = 0; i < n; i++){
			string s = "";
			for (int j = 0; j < n; j++){
				if (adj[i][j] == 1)
					s += 'L';
				else s += 'S';
			}
			printf("%s\n", s.c_str());
		}
	}
}
