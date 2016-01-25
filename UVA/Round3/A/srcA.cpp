// 402

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
	int n, x, t = 0;
	while (cin >> n >> x) {
		t++;
		cout << "Selection #" << t << endl;
		vi c(20, 0);
		for (int i = 0; i < 20; i++)
			cin >> c[i];
		vi p(n+1, 1);
		int total = n;
		if (x >= n) {
			int first = 0;
			for (int i = 1; i <= n; i++) {
				if (p[i] == 1) {
					if (first)
						cout << " ";
					else
						first = 1;
					cout << i;
				}
			}
			cout << endl;
			cout << endl;
			continue;
		}
		for (int i = 0; i < 20; i++) {
			int s = c[i];
			int cur = s;
			if (s > total)
				continue;
			for (int j = 1; j <= n; j++) {
				if (p[j] == 0)
					continue;
				cur--;
				if (cur == 0) {
					p[j] = 0;
					total--;
					cur = s;
					if (total <= x)
						break;
				}
				if (cur > total)
					continue;
			}
			if (total <= x)
				break;
		}
		int first = 0;
		for (int i = 1; i <= n; i++) {
			if (p[i] == 1) {
				if (first)
					cout << " ";
				else
					first = 1;
				cout << i;
			}
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}

