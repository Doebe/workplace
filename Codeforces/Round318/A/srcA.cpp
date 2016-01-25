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
	int n, a, l;
	cin >> n;
	ii sum(0, 0);
	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i == 0)
			l = a;
		if (a >= l) {
			sum.first += a;
			sum.second++;
			if (a == l)
				num++;
		}
	}
	if (num == 1 && sum.first == l)
		cout << 0 << endl;
	else cout << sum.first / (sum.second - num + 1) + 1 - l << endl;
//
//	priority_queue<int> c;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		if (i == 0) {
//			l = a;
//			continue;
//		}
//		c.push(a);
//	}
//	int dif = 0;
//	while (!c.empty()) {
//		int cur = c.top(); c.pop();
//		if (l > cur)
//			break;
//		l++;
//		cur--;
//		dif++;
//		c.push(cur);
//	}
//	cout << dif << endl;
	return 0;
}
