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
vi primes, palins;
int pin[2000000];
int pan[2000000];

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs[i]){
			for (ll j = i * i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			primes.push_back((int)i);
			if ((int)i == 2)
				pin[2] = 1;
			else {
				for (int j = primes[primes.size()-2] + 1; j <= i; j++)
					pin[j] = pin[j-1];
				pin[i]++;
			}
		}
}

bool ispalin(string s, int i, int j) {
	if (i >= j)
		return true;
	if (s[i] == s[j])
		return ispalin(s, i+1, j-1);
	return false;
}

void palin(int upperbound) {
	for (int i = 1; i <= upperbound; i++) {
		stringstream ss;
		string s;
		ss << i;
		s = ss.str();
		if (ispalin(s, 0, s.size()-1)) {
			palins.push_back((int)i);
			if ((int)i == 1)
				pan[i] = 1;
			else {
				for (int j = palins[palins.size()-2] + 1; j <= i; j++)
					pan[j] = pan[j-1];
				pan[i]++;
			}
		}
	}
}

int main(){
	pin[1] = 0;
	sieve(2000000);
	palin(2000000);
//	for (int i = 0; i < 200; i++)
//		printf("pin[%d] = %d\n", i, pin[i]);
//	for (int i = 0; i < 200; i++)
//		printf("pan[%d] = %d\n", i, pan[i]);
	double p , q;
	cin >> p >> q;
	double A = p / q;
//	cout << A << endl;
	int found = 0;
	int i = min(primes.size(), palins.size());
	for (; i >= 1; i--) {
		if (pin[i] <= A * pan[i]) {
			found = 1;
			cout << i << endl;
			break;
		}
	}
	if (!found)
		cout << "Palindromic tree is better than splay tree" << endl;
	return 0;
}
