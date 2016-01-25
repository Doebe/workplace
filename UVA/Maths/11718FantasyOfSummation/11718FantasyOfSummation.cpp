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

ll c, n, K, MOD, cur, sum;

ll expo(ll k){
	if (k == 0)
		return 1;
	if (k == 1)
		return n % MOD;
	ll mod = expo(k / 2);
	if (k % 2 == 0)
		return (mod * mod) % MOD;
	return (mod * mod * (n % MOD)) % MOD;
}

int main(){
	ll rst;
	cin >> c;
	for (int i = 0; i < c; i++){
		cin >> n >> K >> MOD;
		sum = 0;
		for (int j = 0; j < n; j++){
			cin >> cur;
			sum += (cur % MOD);
		}
		rst = (expo(K - 1) * ((K * sum % MOD) % MOD)) % MOD;
		cout << "Case " << i + 1 << ": " << rst << endl;
	}
	return 0;
}
