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

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs[i]){
			for (ll j = i * i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			primes.push_back((int)i);
		}
}

int memo[10000010];

int main(){
	ll t, a, b, k;
	sieve(10000010);
	MEM(memo, -1);
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> a >> b >> k;
		int cnt = 0;
		for (int i = a; i <= b; i++) {
			if (memo[i] == k) {
				cnt++;
				continue;
			}
			if (memo[i] == -1) {
				memo[i] = 0;
				for (int j = 0; j < primes.size(); j++) {
					if (i % primes[j] == 0)
						memo[i]++;
				}
				if (memo[i] == k)
					cnt++;
			}
//			cout << i << " " << memo[i] << endl;
		}
		printf("Case #%d: %d\n", c, cnt);
	}
	return 0;
}
