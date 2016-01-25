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
	int n, t;
	cin >> n >> t;
	string a, b;
	getline(cin, a);
	getline(cin, a);
	getline(cin, b);

	string ans = a;
	int s = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == b[i])
			s++;

	int x = n - t - s;
	if (x*2 > n - s) {
		cout << -1 << endl;
		return 0;
	}

	if (x > 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i] && x > 0) {
				ans[i] = a[i];
				int j;
				int found = 0;
				for (j = i; j < n; j++) {
					if (a[i] != b[i]) {
						ans[i] = b[i];
						found = 1;
						break;
					}
				}
				if (!found) {
					cout << -1 << endl;
					return 0;
				}
				x--;
				i = j+1;
			} else if (a[i] != b[i]) {
				if (a[i] != 'a' && b[i] != 'a')
					ans[i] = 'a';
				else if (a[i] != 'b' && b[i] != 'b')
					ans[i] = 'b';
				else ans[i] = 'c';
			}
		}
	} else if (x < 0) {
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i] && x < 0) {
				if (a[i] == 'a')
					ans[i] = 'b';
				else ans[i] = 'a';
				x++;
			} else if (a[i] != b[i]) {
				if (a[i] != 'a' && b[i] != 'a')
					ans[i] = 'a';
				else if (a[i] != 'b' && b[i] != 'b')
					ans[i] = 'b';
				else ans[i] = 'c';
			}
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (a[i] != b[i]) {
				if (a[i] != 'a' && b[i] != 'a')
					ans[i] = 'a';
				else if (a[i] != 'b' && b[i] != 'b')
					ans[i] = 'b';
				else ans[i] = 'c';
			}
		}
	}

	cout << ans << endl;
	return 0;
}
