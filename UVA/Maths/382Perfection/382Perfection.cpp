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

int sumDiv(int N){
	int PF_idx = 0, PF = primes[PF_idx], ans = 1;
	while (PF * PF <= N){
		int power = 0;
		while (N % PF == 0){
			N /= PF; power++;
		}
		ans *= ((int)pow((double)PF, power + 1.0) - 1) / (PF - 1);
		PF = primes[++PF_idx];
	}
	if (N != 1) ans *= ((int)pow((double)N, 2.0) - 1) / (N - 1);
	return ans;
}

int n;

int main(){
	cout << "PERFECTION OUTPUT\n";
	while (true){
		cin >> n;
		if (n == 0)
			break;
		cout.width(5);
		cout << right << n << "  ";
		sieve(n);
		int rst = sumDiv(n) - n;
		if (rst == n)
			cout << "PERFECT" << endl;
		else if (rst < n)
			cout << "DEFICIENT" << endl;
		else cout << "ABUNDANT" << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}
