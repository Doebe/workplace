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
typedef pair<int, ii> iii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int n, a, b;
	cin >> n;
	int a1[n];
	int a2[n];
	int a3[n];
	a1[0] = 0;
	a2[n-1] = 0;
	for (int i = 0; i < n-1; i++) {
		cin >> a;
		if (i == 0) {
			a1[1] = a;
			continue;
		}
		a1[i+1] = a1[i] + a;
	}
	for (int i = 0; i < n-1; i++) {
		cin >> a;
//		cout << a << endl;
		a2[i] = a;
	}
	for (int i = n-2; i >= 0; i--) {
		a2[i] += a2[i+1];
	}
	for (int i = 0; i < n; i++) {
		cin >> b;
		a3[i] = b;
	}
//	for (int i = 0; i < n; i++)
//		cout << a1[i] << " ";
//	cout  << endl;
//	for (int i = 0; i < n; i++)
//		cout << a2[i] << " ";
//	cout  << endl;
//	for (int i = 0; i < n; i++)
//		cout << a3[i] << " ";
//	cout  << endl;

	ii mn = ii(INF, 0);
	int m2 = INF;
	for (int i = 0; i < n; i++) {
		if (mn.first > a1[i] + a2[i] + a3[i]) {
			mn.first = a1[i] + a2[i] + a3[i];
			mn.second = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == mn.second)
			continue;
		int tmp = a1[i] + a2[i] + a3[i];
		m2 = min(m2, tmp);
	}
	cout << mn.first + m2 << endl;
	return 0;
}
