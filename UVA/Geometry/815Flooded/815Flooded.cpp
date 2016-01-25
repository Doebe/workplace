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

int main() {
	ll m, n, v, r = 0;
	while (scanf("%lld %lld", &m, &n) && m && n) {
		r++;
		ll t = m * n;
		ll reg[t];
		reg[0] = 0;
		for (ll i = 1; i <= t; i++)
			scanf("%lld", &reg[i]);
		scanf("%lld", &v);
		sort(reg + 1, reg + t + 1);
//		for (int i = 0; i <= t; i++)
//			cout << reg[i] << " ";
//		cout << endl;
		vi water;
		water.push_back(0);
		double h;
		int floor;
		for (ll i = 2; i <= t; i++) {
			water.push_back((reg[i]-reg[i-1]) * (i-1) * 100);
			v -= water[i-1];
			if (v <= 0){
				h = reg[i-1] + (water[i-1] + v) / 100.0 / (i-1);
				floor = (i-1);
				break;
			}
		}
//		for (ll i = 0 ; i <= t; i++)
//			cout << water[i] << " ";
//		cout << endl;
		if (v > 0) {
			h = reg[t] + v / 100.0 / t;
			floor = t;
		}
		printf("Region %lld\nWater level is %.2lf meters.\n%.2lf percent of the region is under water.\n\n", r, h, (100.0 * floor) / t);
	}
	return 0;
}
