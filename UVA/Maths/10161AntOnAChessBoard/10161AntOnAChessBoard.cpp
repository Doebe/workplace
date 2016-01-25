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
	ll n;
	long x, y;
	while (1){
		cin >> n;
		if (n == 0)
			break;
		long sq = floor(sqrt(n));
		if (sq % 2 == 0){
			ll diag = sq * sq - sq + 1;
			long dif = n - diag;
			if (dif < sq){
				x = sq;
				y = sq - dif;
			}else if (dif <= 2 * sq){
				x = sq + 1;
				y = dif - sq + 1;
			}else {
				x = 3 * sq - dif + 1;
				y = sq + 1;
			}
		}else{
			ll diag = sq * sq - sq + 1;
			long dif = n - diag;
			if (dif < sq){
				x = sq - dif;
				y = sq;
			}else if (dif <= 2 * sq){
				x = dif - sq + 1;
				y = sq + 1;
			}else {
				x = sq + 1;
				y = 3 * sq - dif + 1;
			}
		}
		cout << x << " " << y << endl;
	}
}
