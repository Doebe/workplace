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
typedef vector<double> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int t, n, a;
	cin >> t;
	while (t--) {
		cin >> n;
		int num[n+1];
		for (int i = 1; i <= n; i++)
			cin >> num[i];
		sort(num+1, num+n+1);
		ll dp[n+1];
		MEM(dp, 0);
		ll total = 0;
		ll p = 0;
		for (int i = 4; i <= n; i++) {
			if (i == 4) {
				int a = num[1], b = num[2], c = num[3], d = num[4];
				dp[i] = 4 * (d - a) + 2 * abs(a + d - b - c);
				p++;
			}
			else {
				dp[i] = dp[i-1] + (6 * (num[i] - num[i-1])) * p;
				for (int j = 1; j < i - 2; j++)
					for (int k = j + 1; k < i - 1; k++) {
						int a = num[j], b = num[k], c = num[i-1], d = num[i];
						dp[i] += 4 * (d - a) + 2 * abs(a + d - b - c);
						p++;
					}
				cout << p << endl;
			}
			total += dp[i];
		}
		cout << total << endl;
	}
	return 0;
}

