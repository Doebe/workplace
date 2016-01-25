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
	int n, a;
	scanf("%d", &n);
	int mx = 0;
	map<int, iii> m;
	for (int i = 1;i <= n; i++) {
		cin >> a;
		if (!m.count(a)) {
			m[a] = iii(1, ii(i, i));
		} else {
			m[a].first++;
			m[a].second.second = i;
		}
		mx = max(mx, m[a].first);
//		cout << mx << endl;
	}
	iii ans;
	ans.first = INF;
	for (map<int, iii>::iterator i = m.begin(); i != m.end(); i++) {
//		cout << i->first << endl;
		if (i->second.first == mx) {
			int dif = i->second.second.second - i->second.second.first;
			if (ans.first > dif) {
				ans.first = dif;
				ans.second.first = i->second.second.first;
				ans.second.second = i->second.second.second;
			}
		}
	}
	cout << ans.second.first << " " << ans.second.second << endl;
	return 0;
}
