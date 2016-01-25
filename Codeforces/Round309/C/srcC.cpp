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
	int k, n;
	ll ball[1002][1002];
	cin >> k;
	vi b;
	MEM(ball, 0);
	while (k--){
		cin >> n;
		b.push_back(n);
	}
	for (int i = 0; i < 1002; i++){
		for (int j = 0; j < 1002; j++){
			if (i == 0){
				ball[i][j] = 1;
				continue;
			}
			if (j == 0){
				ball[i][j] = 1;
				continue;
			}
			ball[i][j] = (ball[i-1][j] + ball[i][j-1]) % 1000000007;
		}
	}
//	for (int i = 0; i < 10; i++){
//		for (int j = 0; j < 10; j++)
//			cout << ball[i][j] << " ";
//		cout << endl;
//	}
	ll sum = 0, total = 0, ans = 1;
	for (int i = 0; i < b.size(); i++){
		for (int j = 0; j <= total; j++){
			if (b[i] == 1)
				sum = 1;
			else
				sum += ball[b[i]-2][j];
//			cout << "sum= " << sum << endl;
			sum %= 1000000007;
		}
		ans *= sum;
//		cout << "ans= " << ans << endl;
		ans %= 1000000007;
		total += b[i];
		sum = 0;
	}
	cout << ans << endl;
	return 0;
}
