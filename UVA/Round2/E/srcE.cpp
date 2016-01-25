// 725

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
	int n, d[10], c = 0;
	while (cin >> n && n) {
		c++;
		if (c > 1)
			cout << endl;
		int found = 0;
		for (int i = 10000; i < 100000; i++) {
			if (i % n)
				continue;
			MEM(d, 0);
			int tmp = i, no = 0;
			for (int j = 1; j <= 5; j++) {
				int p = (tmp % (int)pow(10, j)) / (int)pow(10, j-1);
				d[p]++;
				if (d[p] > 1) {
					no = 1;
					break;
				}
			}
			if (no)
				continue;
			tmp = i / n;
			for (int j = 1; j <= 5; j++) {
				int p = (tmp % (int)pow(10, j)) / (int)pow(10, j-1);
				d[p]++;
				if (d[p] > 1) {
					no = 1;
					break;
				}
			}
			if (no)
				continue;
			int zero = 0;
			if ((i/n) % 10000 == (i/n))
				zero = 1;
			int ans = i/n;
			cout << i << " / ";
			if (zero)
				cout << 0;
			cout << ans << " = " << n << endl;
			found = 1;
		}
		if (!found)
			cout << "There are no solutions for " << n << "." << endl;
	}
	return 0;
}
