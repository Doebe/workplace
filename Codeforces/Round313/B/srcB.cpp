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
	int a1, b1, a2, b2, a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	if (a2 * b2 + a3 * b3 > a1 * b1) {
		cout << "NO" << endl;
		return 0;
	}
	int hh = 0, hv = 0, vh = 0, vv = 0;
	a2 = min(a2, b2);
	b2 = max(a2, b2);
	a3 = min(a3, b3);
	b3 = max(a3, b3);
	if ((b2 + a3 <= a1 && max(b3, a2) <= b1) || (b2 + a3 <= b1 && max(b3, a2) <= a1))
		vh = 1;
	if ((max(b2, a3) <= a1 && b3 + a2 <= b1) || (max(b2, a3) <= b1 && b3 + a2 <= a1))
		hv = 1;
	if ((a2 + a3 <= a1 && max(b2, b3) <= b1) || (a2 + a3 <= b1 && max(b3, b2) <= a1))
		hh = 1;
	if ((b2 + b3 <= a1 && max(a2, a3) <= b1) || (b2 + b3 <= b1 && max(a2, a3) <= a1))
		vv = 1;
	if (vh || hv || hh || vv)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
