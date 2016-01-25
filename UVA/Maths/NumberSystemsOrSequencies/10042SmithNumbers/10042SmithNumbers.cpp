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
vector<ll> fac, ftr, boo, primes;

ll sumation(ll num){
	ll sum = 0;
	while (num > 0){
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

bool isPrime(int n) {
	if (n == 1) {
		return false;
	}

	for (int i = 0; i < primes.size() && primes[i] < n; i++) {
		if (n % primes[i] == 0) {
			return false;
		}
	}
	return true;
}

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs[i]){
			for (ll j = i * i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			primes.push_back(i);
		}
}

int primeFactors(ll x) {
	int sum = 0;
	ll N = x;
//	cout << "N " << N << endl;
	if (isPrime(N))
		return primeFactors(x+1);
	ll PF_idx = 0, PF = primes[PF_idx];
//	cout << PF << endl;
	while (PF * PF <= N){
		if (PF > sqrt(x) + 1)
			break;
		while (N % PF == 0){
//			cout << "in" << endl;
			N /= PF;
			sum += sumation(PF);
//			cout << sum << " ";
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) {
		sum += sumation(N);
//		cout << sum << " ";
	}
//	cout << endl;
	if (sum == sumation(x))
		return x;
//	cout << cnt << " " <<  cnt + fac[x - 1] << endl;
	return primeFactors(x+1);
}


int main(){
	int t, n;
	sieve(100000);
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		printf("%d\n", primeFactors(n+1));
	}
}
