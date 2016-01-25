// 12050

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
	ll num[20];
	num[1] = 9;
	num[2] = 9;
	for (int i = 3; i < 20; i++) {
		num[i] = 9;
		num[i] *= pow(10, (ceil(i/2.0)-1));
	}
	ll n;
	while (cin >> n && n) {
		int i = 0;
		for (; i < 20; i++) {
			if (num[i] >= n)
				break;
			n -= num[i];
		}
		int digit = (i-1)/2;
		vi dig(i, 1);
		int k = 0;
		while (k < (i+1)/2) {
			ll tmp = (int)pow(10,digit);
			if (k == 0) {
				if (n % tmp)
					dig[k] = 1+n/tmp;
				else dig[k] = n/tmp;
			} else {
				dig[k] = n/tmp;
				if (k == (i-1)/2)
					dig[k] = (dig[k]+10-1)%10;
			}
			n %= tmp;
			k++;
			digit--;
		}
		for (int j = k; j < dig.size(); j++)
			dig[j] = dig[dig.size()-1-j];
		for (int j = 0; j < dig.size(); j++)
			cout << dig[j];
		cout << endl;
	}
	return 0;
}
