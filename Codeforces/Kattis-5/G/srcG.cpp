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
	int k, t, n, m;
	scanf("%d", &k);
	while (k--) {
		scanf("%d %d %d", &t, &n, &m);
		double R, r, l, a, b, c;
		r = 1.0;
		R = sin(PI/n) * r / (1-sin(PI/n));
		l = R+r;
//		if (m == 1) {
//			printf("%d %.3lf %.3lf\n", t, R, 2*PI*R+2*m*R);
//			continue;
//		}
		for (int i = 2; i <= m; i++) {
			r = R;
//			cout << (abs(r / l - sin(PI/n)) < eps) << endl;
			a = l*l/r/r-1;
			b = -(2*l*l*cos(PI/n)/r+2*r);
			c = l*l*cos(PI/n)*cos(PI/n);
//			cout << b*b-4*a*c << endl;
			R = (-b + sqrt(b*b-4*a*c))/2/a;
			l *= R/r;
//			cout << R << endl;
		}
		printf("%d %.3lf %.3lf\n", t, R, 2*PI*R+2*n*R);
	}
	return 0;
}
