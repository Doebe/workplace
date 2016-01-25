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
	int n, a;
	cin >> n;
	vi t;
	vi ans(n, INF);
	for (int i = 0; i < n; i++) {
		cin >> a;
		t.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans[i] = 1;
			continue;
		}
		ans[i] = min(ans[i], min(i+1, min(t[i], ans[i-1]+1)));
	}
//	for (int i = 0; i < n; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << endl;
	for (int i = n-1; i >= 0; i--) {
		if (i == n-1) {
			ans[i] = 1;
			continue;
		}
		ans[i] = min(ans[i], min((n-i), min(t[i], ans[i+1]+1)));
	}
	int last = 0;
	for (int i = 0; i < n; i++) {
		last = max(last, ans[i]);
//		cout << ans[i] << " ";
	}
//	cout << endl;
	cout << last << endl;
	return 0;
}
