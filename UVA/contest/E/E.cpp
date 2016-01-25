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
typedef vector<ll> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

ll n,d;

ll _sieve_size;
bitset<10000010> bs;
vi primes, pf, df;

map<int,int> pf2[101];


void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i*i <= _sieve_size; i++)
		if (bs[i]){
			for (ll j = i * i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			primes.push_back((int)i);
		}
}

bool primeFactors(map<int,int> &fm,ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF_idx < primes.size() && PF * PF <= N){
//			printf("N = %lld PF = %lld\n",N, PF);
		while (N % PF == 0){
			if(PF > n)return false;
			N /= PF;
			if(!fm.count(PF))fm[PF] = 0;
			fm[PF]++;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) {
		if(!fm.count(N))fm[N] = 0;
		fm[N]++;
		factors.push_back(N);
		if(N > n)return false;
	}
	return true;
}
bool primeFactorsD(map<int,int> &fm,ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF_idx < primes.size() && PF * PF <= N){
		while (N % PF == 0){
			if(PF > n){
				return false;
			}
			N /= PF;
			if(!fm.count(PF))fm[PF] = 0;
			fm[PF]++;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) {
		if(!fm.count(N))fm[N] = 0;
		fm[N]++;
		factors.push_back(N);
		if(N > n)return false;
	}
	return true;
}

int main(){
	n = 101;
	sieve(1000000);
	for (int i = 1; i <= 100; ++i)
		primeFactors(pf2[i],i);

	for (int i = 1; i < 100; ++i)
		for(map<int,int>::iterator it = pf2[i].begin() ; it != pf2[i].end(); ++it)
			pf2[i+1][it->first] += 	it->second;

	while(scanf("%lld %lld", &n,&d) == 2 && (n || d)){
		ll totalD = 1;
		if(d < 0)
			d *= -1;

		map<int,int> D;
		if(primeFactors(D,d)){
			for(map<int,int>::iterator it = pf2[n].begin() ; it != pf2[n].end(); ++it)
				totalD *= (it->second - D[it->first] + 1);
			if(totalD<=0)	printf("0\n");
			else
				printf("%lld\n", totalD);
		}else
				printf("0\n");
	}
}
