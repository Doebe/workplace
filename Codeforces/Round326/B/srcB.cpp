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

int main(){
	ll n;
	vi fac;
	cin >> n;
	for (ll i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			fac.push_back(i);
			fac.push_back(n/i);
		}
	}
	sort(fac.begin(), fac.end());
//	for (int i = 0; i < fac.size(); i++)
//		cout << fac[i] << " ";
//	cout << endl;
	for (ll i = fac.size()-1; i >= 0; i--) {
		int found = 0;
		for (ll j = 2; j * j <= fac[i]; j++) {
			if (fac[i] % (j * j) == 0) {
				found = 1;
				break;
			}
		}
		if (!found) {
			cout << fac[i] << endl;
			break;
		}
	}
	return 0;
}
