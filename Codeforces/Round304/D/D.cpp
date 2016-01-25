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
vi fac, ftr;

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

int primeFactors(ll x) {
	int cnt = 0;
	ll N = x;
	ll PF_idx = 0, PF = primes[PF_idx];
	bool found = false;
	while (PF * PF <= N){
		while (N % PF == 0){
			N /= PF;
			cnt++;
			if (fac[N] > 0){
				cnt += fac[N];
				found = true;
				break;
			}
		}
		if (found)
			break;
		PF = primes[++PF_idx];
	}
	if (!found && N != 1) cnt++;
	ftr[x] += cnt + ftr[x-1];
//	cout << cnt << " " <<  cnt + fac[x - 1] << endl;
	return fac[x] = cnt;
}

int main(){
	sieve(5000000);
	fac.assign(5000000, 0);
	ftr.assign(5000000, 0);
	for (int i = 2; i <= 5000000; i++)
		primeFactors(i);
	int t;
	scanf("%d", &t);
	while (t--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", (ftr[a] - ftr[b]));
	}
}
