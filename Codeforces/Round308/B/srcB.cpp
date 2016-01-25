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
	int n;
	cin >> n;
//	if (n < 10){
//		cout << n << endl;
//	}
//	else {
		ll sums[10];
		MEM(sums, 0);
		for (int i = 1; i < 10; i++){
			sums[i] = (pow(10, i) - pow(10, i-1)) * i + sums[i-1];
//			cout << sums[i] << endl;
		}
		ll sum = 0;
		for (int i = 9; i >= 0; i--){
			ll ex = pow(10, i);
//			cout << ex << endl;
			if (n < ex)
				continue;
//			cout << n-ex+1 << " " << i+1 << endl;
			sum += (n - ex + 1) * (i + 1);
			sum += sums[i];
//			cout << i << " " << sum << " " << sums[i] << endl;
			break;
		}
		cout << sum;
//	}
	return 0;
}
