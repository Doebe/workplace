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
	scanf("%d\n", &n);
	while (n--) {
		string digits;
		getline(cin, digits);
		int mx = 0;
		int remove[251];
		for (int D = 0; D <= 9; ++D)
			for (int k = 1; k <= digits.length(); ++k) {
				int add = 0, curDigit;
				MEM(remove, 0);
				for (int i = 0; i + k <= digits.length(); ++i){
					add -= remove[i];
					curDigit = (digits[i] - '0' + add) % 10;
					int need = (10 - curDigit + D) % 10;
					add += need;
					remove[i + k] = need;
				}
				int yes = 1, newDigit;
				for (int i = digits.length()-k+1; i < digits.length(); ++i) {
					add -= remove[i];
					newDigit = (digits[i] - '0' + add) % 10;
					int need = (10 - newDigit + D) % 10;
					if (need){
						yes = 0;
						break;
					}
				}
				if (yes)
					mx = max(mx, k);
			}
		printf("%d\n", mx);
	}
	return 0;
}
