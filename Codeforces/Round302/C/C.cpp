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


vi a;
int n, m, b, mod;
int memo[502][502];

int main(){
	scanf("%d %d %d %d", &n, &m, &b, &mod);
	a.assign(n+1, 0);
	MEM(memo, 0);
	memo[0][0] = 1;
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		for (int j = a[i]; j <= b; j++){
			for (int k = 1; k <= m; k++){
				memo[j][k] += memo[j-a[i]][k-1];
				memo[j][k] %= mod;
			}
		}
	}
	int num = 0;
	for (int i = 0; i <= b; i++)
		num = (num + memo[i][m]) % mod;
	int ans = num % mod;
	printf("%d\n", ans);
}
