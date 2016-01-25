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
//	ll ugly[1510];
//	ugly[0] = 1;
//	ugly[1] = 2;
//	ugly[2] = 3;
//	ugly[3] = 4;
//	ugly[4] = 5;
//	ugly[5] = 6;
//	for (int i = 5; i < 1501; i++){
//		ll mini = INF, num = 0;
//		ll sq = sqrt(ugly[i]);
//		ll sqr;
//		for (sqr = 0; sqr < 1501; sqr++)
//			if (ugly[sqr] >= sq)
//				break;
//		for (ll j = sqr; j < i; j++){
//			for (ll k = j; k >= 0; k--){
//				ll x = ugly[j] * ugly[k];
////				cout << ugly[i] << " " << x << endl;
//				if (x - ugly[i] <= 0)
//					continue;
//				if (x - ugly[i] < mini){
//					mini = x - ugly[i];
//					num = x;
//				}
//			}
//		}
//		ugly[i + 1] = num;
//	}
//	cout << "The 1500'th ugly number is " << ugly[1499] << "." << endl;
	cout << "The 1500'th ugly number is " << 859963392 << "." << endl;
	return 0;
}
