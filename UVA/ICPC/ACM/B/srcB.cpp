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

ll power[63];
vi small, large;

void calculateSmall(ll p, ll q) {
	if (p == q)
		return;
	ll mn = INF, mx = 0;
	for (int i = 0; i < 63; i++) {
		if (power[i] >= p && mn != INF)
			mn = power[i];
		if (power[i] <= q)
			mx = max(mx, power[i]);
	}
	if (mn == mx) {
		small.push_back(mn - p);
		mn /= 2;
		p -= mn;
		calculate(p, mn-1);
	} else {
		calculate(p, mn-1);
		calculate(mx, q);
	}
}

void calculateLarge(ll p, ll q) {
	if (power[p] == q)
		return;
	large.push_back(q - power[p] + 1);
	p -= 1;
	ll mn = INF, mx = 0;
	for (int i = p; i < 63; i++) {
		if ( mn != INF)
			mn = power[i];
		if (power[i] <= q)
			mx = max(mx, power[i]);
	}
	if (mn == mx) {
		small.push_back(mn - p);
		calculate(p, mn-1);
	} else {
		calculate(p, mn-1);
		calculate(mx, q);
	}
}

int main(){
	for (int i = 0; i < 63; i++) {
		power[i] = 1LL << i;
//		cout << power[i] << endl;
	}
	int n;
	ll p, q;
	cin >> n;
	for (int c = 1; c <=n; c++) {
		small.clear();
		large.clear();
		cin >> p >> q;
		if (p == q)
			cout << p << endl;
		else {
			ll mn = INF, mx = 0;
			for (int i = 0; i < 63; i++) {
				if (power[i] >= p && mn != INF)
					mn = i;
				if (power[i] <= q)
					mx = i;
			}
			calcualteSmall(p, mn);
			calculateLarge(mx, q);
		}
	}
	return 0;
}
