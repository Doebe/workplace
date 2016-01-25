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
	ll m, h1, h2, x1, x2, y1, y2, a1, a2;
	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	ll n = 100000000;
	bool yes = false;
	int i;
	for (i = 1; i < n; i++){
		h1 = (x1 * h1 + y1) % m;
//		cout << h1 << endl;
		h2 = (x2 * h2 + y2) % m;
//		cout << h2 << endl;
		if (h1 == a1 && h2 == a2){
			yes = true;
			break;
		}
	}
	if (yes)
		cout << i << endl;
	else cout << -1 << endl;
}
