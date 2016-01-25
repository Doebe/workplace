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
map<int, int> factors;

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
			if (PF != 2 && PF != 3)
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	if (N != 1 && N != 2 && N != 3) factors.push_back(N);
	return factors;
}


int main(){
	int n, a;
	cin >> n;
//	vector<vi> p;
	vi p;
	int c;
	bool yes = true;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (a % 2 == 0)
			a /= 2;
		while (a % 3 == 0)
			a /= 3;
		if (i == 0)
			c = a;
		else if (c != a) {
			yes = false;
			break;
		}

//		vi tmp = primeFactors(a);
//		p.push_back(tmp);
//		if (i == 0)
//			for (int j = 0; j < p[i].size(); j++)
//				factors[p[i][j]]++;
//		else {
//			int tmp = 0;
//			for (int j = 0; j < p[i].size(); j++) {
//				if (j == 0) {
//					tmp++;
//					continue;
//				}
//				if (p[i][j] == p[i][j-1])
//					tmp++;
//				else {
//					if (factors[p[i][j-1]] == tmp) {
//						tmp = 0;
//						continue;
//					}
//					yes = false;
//					break;
//				}
//			}
//			if (!yes)
//				break;
//		}
	}
		if (yes)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	return 0;
}
