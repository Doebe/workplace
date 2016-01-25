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
	int n, a, b, num, sum;
	cin >> n;
	while (n--) {
		vi val;
		cin >> num >> sum;
		while (num--) {
			cin >> a >> b;
			val.push_back(a*a+b*b);
		}
		sum *= sum;
		int dp[val.size()+2][sum+2];
		MEM(dp, 0);
		for (int i = 0; i < val.size()+1; i++) {
			for (int j = 0; j < sum+2; j++) {
				if (j == 0 || i == 0) {
					continue;
				}
				if (val[i-1] > j) {
					dp[i][j] = dp[i-1][j];
					continue;
				}
				dp[i][j] = max(dp[i-1][j], 1 + dp[i-1][j-val[i-1]]);
			}
		}
//		cout << dp[lug.size()][sum] << " " << sum << endl;
		for (int i = 0; i < val.size()+1; i++) {
			for (int j = 0; j < sum + 1; j++)
				cout << dp[i][j] << " ";
			cout << endl;
		}
		cout << dp[val.size()][sum] << endl;
	}
	return 0;
}
