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
typedef pair<ll,ll> ii;
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

vi primeFactors(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N){
		while (N % PF == 0){
			N /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

int prime[6] = {2, 3, 5, 7, 11, 13};

ll calc (int nf) {
	vi f = primeFactors(nf);
	sort(f.begin(), f.end());
	reverse(f.begin(), f.end());
	printf("prime factors starts: \n");
	for (int i = 0; i < f.size(); i++)
		cout << f[i] << " ";
	cout << endl;
	printf("prime factors ends: \n");
//	for (int i = f.size() - 1; i >= 0; i--) {
//		ll cur = pow(prime[i], f[i]-1);
//		cout << prime[i] << " " << f[i]-1 << endl;
//		ii small(-1, cur);
//		for (int j = 0; j < i; j++) {
//			ll tmp = pow(prime[j], f[j] * f[i]-1) / pow(prime[j], f[j]-1);
//			if (small.second > tmp) {
//				small.first = j;
//				small.second = tmp;
//			}
//		}
//		if (small.first != -1) {
//			f[small.first] *= f[i];
//			f[i] = 1;
//		}
//	}
//	ll ans = 1;
//	for (int i = 0; i < f.size(); i++) {
////		cout << prime[i] << " " << f[i] - 1 << endl;
//		ans *= pow(prime[i], f[i]-1);
//	}
	cout << "ans is : " << ans << endl;
	return ans;
}

int main(){
	sieve(1000);
	int num;
	while (scanf("%d", &num) && num) {
		int nf1 = num * 2, nf2 = num * 2 - 1;
		ll ans1 = calc(nf1), ans2 = calc(nf2);
		if (ceil(sqrt(ans2)) == sqrt(ans2))
			cout << min(ans1, ans2) << endl;
		else cout << ans1 << endl;
	}
}
