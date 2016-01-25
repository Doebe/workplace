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
	ll a, b;
	while(cin >> a >> b){
		if (a > b){
			ll temp = a;
			a = b;
			b = temp;
		}
		ll la = ceil(sqrt(a+1));
		ll lb = ceil(sqrt(b+1));
		double h = 0;
		if (a % 2 == la % 2)
			h += sqrt(3) / 3.0;
		else h += sqrt(3) / 6.0;
		if (b % 2 == lb % 2)
			h += sqrt(3) / 6.0;
		else h += sqrt(3) / 3.0;
		h += (lb - la - 1) * sqrt(3) / 2.0;
		ll ha = a - (pow(la-1, 2) - 1) - la;
		ll hb = b - (pow(lb-1, 2) - 1) - lb;
//		cout << a << ha << la;
//		cout << b << hb << lb;
		double w = abs(hb - ha) / 2.0;
//		cout << h << " " << w << endl;
		double dist = sqrt(h * h + w * w);
		printf("%.3lf\n", dist);
	}
	return 0;
}
