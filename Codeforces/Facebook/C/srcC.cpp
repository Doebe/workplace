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

ll dpfree[2010][2010], dpful[2010][2010];
ll mod = 1000000007;

ll free(int a, int b){
	if (a <= 0 || b < 0)
		return 0;
	if (a <= b)
		return 0;
	if (dpfree[a][b])
		return dpfree[a][b];
	if (b == 0)
		return dpfree[a][b] = 1;
	return dpfree[a][b] = (free(a-1, b) + free(a, b-1)) % mod;
}

ll ful(int a, int b) {
//	cout << a << " " << b << endl;
	if (a < 0 || b < 0)
		return 0;
	if (a > b)
		return 0;
	if (dpful[a][b])
		return dpful[a][b];
	if (b == 0)
		return dpful[a][b] = 1;
	return dpful[a][b] = (ful(a-1, b) + ful(a, b-1)) % mod;
}


int main(){
	int t, a, b;
	MEM(dpfree, 0);
	MEM(dpful, 0);
	scanf("%d\n", &t);
	for (int c = 1; c <= t; c++) {
		scanf("%d-%d\n", &a, &b);
//		printf("Case #%d: %lld %lld\n", c, free(a, b), ful(b, b));
		ll ans1 = free(a, b);
		ll ans2 = ful(b, b);
		cout << "Case #" << c << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}
