// 10750

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
typedef pair<double, ii> dii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int c, n, x, y;
	cin >> c;
	for (int i = 0; i < c; i++) {
		if (i > 0)
			cout << endl;
		cin >> n;
		vii p;
		dii best = dii(1e9, ii(-1, -1));
		while (n--) {
			cin >> x >> y;
			for (int i = 0; i < p.size(); i++) {
				double d = sqrt((y-p[i].second)*(y-p[i].second) + (x-p[i].first)*(x-p[i].first));
				if (best.first > d) {
					best.first = d;
					best.second.first = x;
					best.second.second = y;
//					cout << best.first << " " << best.second.first << " " << best.second.second << endl;
				}
			}
			p.push_back(ii(x, y));
		}
		cout << fixed << setprecision(3) << (double)best.second.first << " " << (double)best.second.second << endl;
	}

	return 0;
}
