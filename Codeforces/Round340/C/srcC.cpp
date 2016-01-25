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
typedef pair<double, double> dd;
typedef pair<ll, ll> llll;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	ll n, x1, x2, y1, y2, x, y;
	ll r1, r2;
	ll d1, d2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	vector<llll> c;
	ll mn = 1e15;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		d1 = (x-x1)*(x-x1) + (y-y1)*(y-y1);
		d2 = (x-x2)*(x-x2) + (y-y2)*(y-y2);
		c.push_back(dd(d1, d2));
	}
	for (int i = 0; i < n; i++) {
		d1 = c[i].first;
		d2 = c[i].second;
		r1 = d1, r2 = 0;
		for (int j = 0; j < n; j++)
			if (c[j].first > d1)
				r2 = max(r2, c[j].second);
		mn = min(mn, r1+r2);
		r1 = 0, r2 = d2;
		for (int j = 0; j < n; j++)
			if (c[j].second > d2)
				r1 = max(r1, c[j].first);
		mn = min(mn, r1+r2);
	}
	cout << mn << endl;
	return 0;
}
