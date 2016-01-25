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
	int t, b, m, n, mn;
	string line;
	scanf("%d\n", &t);
	for (int c = 1; c <= t; c++) {
		getline(cin , line);
		mn = INF;
		b = line.size();
		for (n = 2; n < b; n++) {
			if (b % n == 0) {
				m = b / n;
				char clrN[n];
				int d = 0, yes = 1, l = 0, r = n, u = 0, x = m, p = 0;
				for (; p < n; p++) {
					clrN[p] = line[p];
//					cout << clrN[p];
				}
				d++;
				u++;
				while (r > l && x > u) {
					if (d % 4 == 0) {
						for (int i = l; i < r; i++, p++) {
							if (clrN[i] != line[p]) {
								yes = 0;
//								if (n == 6)
//								printf("Error at %d, clrN[%d] is %c, line[%d] is %c.\n", i, i, clrN[i], p, line[p]);
								break;
							}
//							cout << clrN[i];
						}
						d++;
						u++;
						if (!yes)
							break;
					} else if (d % 4 == 1) {
						for (int i = u; i < x; i++, p++) {
							if (line[p] != line[p-1]) {
								yes = 0;
//								if (n == 6)
//								printf("Error at %d, clrN[%d] is %c, line[%d] is %c.\n", i, i, clrN[i], p, line[p]);
								break;
							}
//							cout << line[p];
						}
						d++;
						r--;
						if (!yes)
							break;
					} else if (d % 4 == 2) {
						for (int i = r-1; i >= l; i--, p++) {
							if (clrN[i] != line[p]) {
//								if (n == 6)
//								printf("Error at %d, clrN[%d] is %c, line[%d] is %c.\n", i, i, clrN[i], p, line[p]);
								yes = 0;
								break;
							}
//							cout << clrN[i];
						}
						d++;
						x--;
						if (!yes)
							break;
					} else {
						for (int i = x-1; i >= u; i--, p++) {
							if (line[p] != line[p-1]) {
//								printf("Error at %d, clrN[%d] is %c, line[%d] is %c.\n", i, i, clrN[i], p, line[p]);
								yes = 0;
								break;
							}
//							cout << line[p];
						}
						d++;
						l++;
						if (!yes)
							break;
					}
				}
				if (yes)
					mn = min(mn, n + m);
//				cout << endl;
			}
		}
		if (mn == INF)
			printf("Case %d: -1\n", c);
		else printf("Case %d: %d\n", c, mn);
	}
	return 0;
}
