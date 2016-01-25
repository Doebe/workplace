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
	int a, b, k, m, n;
	vi aa, bb;
	cin >> a >> b >> k >> m;
	for (int i = 0; i < a; i++){
		cin >> n;
		aa.push_back(n);
//		cout << aa[i] << " ";
	}
//cout << endl;
	for (int i = 0; i < b; i++){
		cin >> n;
		bb.push_back(n);
//		cout << bb[i] << " ";
	}
//cout << endl;

	int cur = INF;
	for (int i = b-1; i >= 0; i--) {
		if (m == 0)
			break;
		cur = bb[i];
		m--;
	}

	int cur2 = -INF;
	for (int i = 0; i < a ; i++) {
		if (k == 0)
			break;
		cur2 = aa[i];
		k--;
	}

//	cout << cur <<" " << cur2 << endl;
	if (cur > cur2)
		cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
