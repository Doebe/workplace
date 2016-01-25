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
	int n, m, maxi;
	while (cin >> n && n){
		int dp[n];
		maxi = 0;
		for (int i = 0; i < n; i++){
			dp[i] = -INF;
			cin >> m;
			cout << i-1 << " " << dp[i-1] << endl;
			dp[i] = dp[i-1] + m;
			maxi = max(maxi, dp[i]);
			dp[i] = max(0, dp[i]);
		}
		if (maxi > 0)
			printf("The maximum winning streak is %d.\n", maxi);
		else printf("Losing streak.\n");
	}
//	int a[1];
//	a[1] = 10;
//	printf("%d\n%d\n%d\n", a[0], a[1], a[2]);
	return 0;
}
