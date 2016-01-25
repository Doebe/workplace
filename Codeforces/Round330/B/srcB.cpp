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
//	cout << 99999 << " " << 9 << endl;
//	for (int i = 0; i < 99999/9; i++)
//		cout << rand(999999999)
	ll n, k, t, mod = 1000000007;
	cin >> n >> k;
	vi a, b;
	vi c(n/k, 0);
	for (int i = 0; i < n/k; i++) {
		cin >> t;
		a.push_back(t);
	}
	for (int i = 0; i < n/k; i++) {
		cin >> t;
		b.push_back(t);
	}
	ll total = 1;
	for (int i = 0; i < n/k; i++) {
		if (b[i] == 0) {
			c[i] += ((int)pow(10, k)-1) / a[i];
			cout << c[i] << endl;
			c[i] -= ((int)pow(10, k-1)-1) / a[i];
			cout << c[i] << endl;
		} else {
			c[i]++;
			c[i] += ((int)pow(10, k)-1) / a[i];
			if ((b[i] * ((int)pow(10, k-1))) % a[i] == 0) {
//				cout << "yes1" << endl;
				c[i]--;
				c[i] -= ((int)pow(10, k-1)-1) / a[i];
			}
			else {
//				cout << "yes2" << endl;
//				cout << c[i] << endl;
				int s = (a[i] - (b[i] * ((int)pow(10, k-1)))%a[i]);
//				cout << s << endl;
				int tmp = (int)pow(10, k-1) - s;
				if (tmp >= 0) {
					c[i]--;
					c[i] -= tmp / a[i];
				}
//				c[i] -= (((int)pow(10, k-1)-1) / (a[i] - (b[i] * ((int)pow(10, k-1)))%a[i]));
//				cout << (b[i] * (int)pow(10, k-1)) << " " << (a[i] - (b[i] * (int)pow(10, k-1))%a[i]) << " " << (((int)pow(10, k-1)-1) / (a[i] - (b[i] * ((int)pow(10, k-1)))%a[i])) << " " << c[i] << endl;
			}
		}
//		cout << "c[" << i << "]: " << c[i] << endl;
		total = (total * c[i]) % mod;
	}
	cout << total << endl;
	return 0;
}
