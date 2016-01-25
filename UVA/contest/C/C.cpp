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
	int n, r, len, wid, left, right, up, down;
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> r;
		len = r * 5;
		wid = len * 3 / 5;
		left = 0 - len * 45 / 100;
		right = len * 55 / 100;
		up = wid / 2;
		down = 0 - up;
		cout << "Case " << i << ":\n";
		cout << left << " " << up << endl;
		cout << right << " " << up << endl;
		cout << right << " " << down << endl;
		cout << left << " " << down << endl;
	}
	return 0;
}
