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
	ll dp[301][301];
	MEM(dp, 0);
	for (int i = 1; i <= 300; ++i) {
		for (int j = 1; j <= i; ++j) {
			if (j == 1) {
				dp[i][j] = 1;
				continue;
			}
			if (i == j) {
				dp[i][j] = 1;
				continue;
			}
			for (int k = 1; k <= j; ++k)
				dp[i][j] += dp[i-j][k];
		}
	}


	for (int i = 1; i <= 300; ++i)
		for (int j = 1; j <= i; ++j)
			dp[i][j] += dp[i][j-1];


	string line;
	while (getline(cin, line)) {
		if (line == "")
			break;
		int n, l1 = -1, l2 = -1;
		stringstream ss(line);
		ss >> n >> l1 >> l2;
		ll sum = 0;
		if (l1 < 0 && l2 < 0)
			sum = dp[n][n];
		else if (l2 < 0)
			sum = dp[n][min(l1, n)];
		else {
			sum = dp[n][min(l2, n)] - dp[n][max(l1-1, 0)];
			if (l2 < l1 || l1 > n)
				sum = 0;
		}
		if (n == 0){
			if (l1 > 0 && l2 > 0)
				sum = 0;
			else sum = 1;
		}
		cout << sum << endl;
	}
	return 0;
}
