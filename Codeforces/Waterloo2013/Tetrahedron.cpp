#include <bits/stdc++.h>
using namespace std;

const int INF = std::numeric_limits<int>::max() / 3;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define are_equal(a,b)fabs((a)-(b))<eps
#define abs_val(a)((a)>=0)?(a):(-(a))
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//
int a, b, c, l, m, n;
int u[3];
int d[3];
bool canTrig(int a, int b, int c) {
	return ((a + b) > c) && ((a + c) > b) && ((c + b) > a);
}

double S(double a, double b, double c) {
	return (a + b + c) * 0.5;
}

double area(double a, double b, double c) {
	double s = S(a, b, c);
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

bool GE(double a, double b) {
//  return a > b || fabs(a-b) < eps;
	return a > b && !(fabs(a - b) < eps);
}

//double sol(double h) {
//
//	if (d * d - h * h < 0 || e * e - h * h < 0 || f * f - h * h < 0)
//		return -1;
//
//	double x = sqrt(d * d - h * h);
//	double y = sqrt(e * e - h * h);
//	double z = sqrt(f * f - h * h);
//
//	double a1 = area(a, x, y) + area(b, x, z) + area(c, y, z);
//	double a2 = area(a, b, c);
//
//	return (a1 - a2);
//}

int main() {
	FASTER;

	int T;
	cin >> T;

	while(T--) {

		int s[6];
		for (int i = 0; i < 6; ++i) {
			cin >> s[i];
		}

//		sort(s, s+6);
		bool ok = false, done = false;
		do {
//			a = s[0];
//			b = s[1];
//			c = s[2];
//			d = s[3];
//			e = s[4];
//			f = s[5];

			for (int i = 0; i < 6; i++)
				for (int j = i+1; j < 6; j++)
					for (int k = j+1; k < 6; k++) {
						u[0] = s[i], u[1] = s[j], u[2] = s[k];
						int tmp = 0;
						for (int x = 0; x < 6; x++)
							if (x != i && x != j && x != k)
								d[tmp++] = s[x];
						a = u[0], b = u[1], c = u[2], l = d[0], m = d[1], n = d[2];

						double v = (4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n));

						if (v > eps) {
							done = true;
							ok = true;
							break;
						}
					}
//			l = s[0];
//			m = s[1];
//			n = s[2];
//			a = s[3];
//			b = s[4];
//			c = s[5];

//			double a1 = area(l,m,n);
//			double a2 = area(l,a,b);
//			double a3 = area(m,b,c);
//			double a4 = area(n,a,c);
//
//			if(canTrig(l,m,n) && canTrig(l,a,b) && canTrig(m,b,c) && canTrig(n,a,c)) {


//			}
		}while(next_permutation(s , s + 6) && !done);

		cout << (ok ? "YES" : "NO") << endl;
	}

	return 0;
}

