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

double x, y, a, b, n, c, d, ix, iy;
double rst;

int main(){
	while (scanf("%lf %lf",&x,&y)==2){
		cin >> n >> a >> b;
		rst = INF;
		double ox = 0;
		double oy = 0;
		while (n--){
			cin >> c >> d;
			if (b - d == 0){
				ix = x;
				iy = b;
			}
			else if (a - c == 0){
				ix = a;
				iy = y;
			}
			else {
				double k = (b - d) / (a - c);
				double t = b - k * a;
				double t2 = y + x / k;
				ix = (t2 - t) / (k + 1 / k);
				iy = k * ix + t;
			}
			if (ix < min(a, c)){
				ix = min(a, c);
				ix == a ? iy = b : iy = d;
			}
			if (ix > max(a, c)){
				ix = max(a, c);
				ix == a ? iy = b : iy = d;
			}
			if (iy < min(b, d)){
				iy = min(b, d);
				iy == b ? ix = a : ix = c;
			}
			if (iy > max(b, d)){
				iy = max(b, d);
				iy == b ? ix = a : ix = c;
			}
			double dist = sqrt((x - ix)*(x - ix) + (y - iy)*(y - iy));
			a = c;
			b = d;
			if (rst > dist){
				ox = ix;
				oy = iy;
				rst = dist;
			}
		}
		printf("%.4lf\n", ox);
		printf("%.4lf\n", oy);
	}
}
