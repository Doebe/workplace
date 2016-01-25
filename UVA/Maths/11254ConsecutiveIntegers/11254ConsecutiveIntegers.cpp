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

//int main(){
//	double n;
//	while (true){
//		cin >> n;
//		if (n < 0)
//			break;
//		int m = ceil(sqrt(n * 2)) - 1;
//		int a = n, b = n;
//	= (2s+n-n^2)/2n
//	}
//	return 0;
//}

int main(){
	ll n;
	while (true){
		cin >> n;
		if (n < 0)
			break;
		int m = ceil(sqrt((double)n * 2)) - 1;
		ll a = n, b = n;
		for (int i = m; i >= 2; i--){
			if (ceil((double)n / i) == (int)((double)n / i)){
				if (i % 2 == 0)
					continue;
				int num = i / 2;
				a = (double)n / i - num;
				b = (double)n / i + num;
				break;
			}
			else if (ceil((double)n / i * 2) == (int)((double)n / i * 2)){
				double mid = (double)n / i;
				int num = i / 2;
				a = ceil(mid) - num;
				b = floor(mid) + num;
				break;
			}
		}
		cout << n << " = " << a << " + ... + " << b << endl;
	}
	return 0;
}
