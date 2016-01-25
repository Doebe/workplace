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

int main(){
	ll n, q, a, t, x, k;
	cin >> n >> q;

	vi h(n+1, 0);
	vi c(n+1, 0);
	vi acc(n+1, 0);
	vi mx(n+1, -INF);
	for (int i = 0; i <= n; i++) {
		cin >> h[i];
		if (i) {
			c[i] = h[i] + h[i-1];
			acc[i] = acc[i-1] + c[i];
		}
		else
			acc[i] = c[i];
	}
	mx[0] = 0;
	for (int i = 1; i <= n; i++) {
		ll dif;
		if (h[i] <= h[i-1])
			dif = (h[i-1]-h[i]) * (h[i-1]-h[i]);
		else
			dif = -(h[i-1]-h[i]) * (h[i-1]-h[i]);
		mx[i] = max(mx[i-1] + dif, dif);
	}
	for (int i = 0; i < q; i++) {
		cin >> t >> x >> k;
		if (!t) {
			c[x] += k-h[x];
			if (x) {
				c[x-1] += k-h[x];
				acc[x] += k-h[x];
			}
			for (int j = x; j <= n; j++)
				acc[j] += k-h[x];
//			cout << x << " " << h[x] << " " << k << endl;
			h[x] = k;
			for (int j = x; j <= n; j++) {
				ll dif;
				if (h[j] <= h[j-1])
					dif = (h[j-1]-h[j]) * (h[j-1]-h[j]);
				else
					dif = -(h[j-1]-h[j]) * (h[j-1]-h[j]);
				mx[j] = max(mx[j-1] + dif, dif);
			}
			continue;
		}
		ll ans = 0;
//		cout << "mxfun: \n";
//		for (int i = 0; i <= n; i++)
//			cout << mx[i] << " ";
//		cout << endl;
//		cout << "cost: \n";
//		for (int i = 0; i <= n; i++)
//			cout << c[i] << " ";
//		cout << endl;
//		cout << "acccost: \n";
//		for (int i = 0; i <= n; i++)
//			cout << acc[i] << " ";
//		cout << endl;
		for (int j = 0; j <= n; j++) {
			if (acc[j] - acc[x] <= k)
				ans = max(ans, mx[j]);
		}
		cout << ans << endl;
	}
	return 0;
}
