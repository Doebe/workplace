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
	string line;
	while (getline(cin, line)) {
		if (line == "0 0 0 0 0 0")
			break;
		stringstream ss(line);
		int a;
		vi p;
		p.push_back(0);
		while (ss >> a)
			p.push_back(a);
		int ans = 0;
		ans += p[6];
		while (p[5]--) {
			ans++;
			if (p[1] > 0)
				p[1] -= min(p[1], 11);
		}
		while (p[4]--) {
			ans++;
			int space = 6*6-4*4;
			if (p[2] > 0) {
				space -= min(p[2], 5) * 4;
				p[2] -= min(p[2], 5);
			}
			if (space>0 && p[1]>0)
				p[1] -= min(p[1], space);
		}
		ans += p[3]/4;
		int space = 6*6 - 3*3*(p[3]%4);
		int n2 = 0, n1 = 0;
		if (p[3]%4 == 3) {
			n2 = min(1, p[2]);
			ans++;
		}
		if (p[3]%4 == 2) {
			n2 = min(3, p[2]);
			ans++;
		}
		if (p[3]%4 == 1) {
			n2 = min(5, p[2]);
			ans++;
		}
		if (space < 36)
			n1 = min(space - n2*4, p[1]);
		p[2] -= n2;
		p[1] -= n1;
		ans += ceil((p[2] * 4 + p[1]) / 36.0);
		cout << ans << endl;
	}
	return 0;
}
