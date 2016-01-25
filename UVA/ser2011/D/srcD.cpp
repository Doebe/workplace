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

int main() {
	int a, b, c, d;
	while (scanf("%d %d %d %d", &a, &b, &c, &d) && a) {
		int cnt = 0;
		while (a != b || a != c || a != d) {
			int e = abs(a - b);
			int f = abs(b - c);
			int g = abs(c - d);
			int h = abs(d - a);
			a = e;
			b = f;
			c = g;
			d = h;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
