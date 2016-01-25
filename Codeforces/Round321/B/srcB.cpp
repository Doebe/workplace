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
typedef pair<ll,ll> ii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef vector<ll> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	ll n, d, m, s;
	cin >> n >> d;
	vii f;
	f.push_back(ii(-1, -1));
	while (n--) {
		cin >> m >> s;
		f.push_back(ii(m, s));
	}
	sort(f.begin()+1, f.end());
//	for (int i = 0; i < f.size(); i++) {
//		cout << f[i].first << " " << f[i].second << endl;
//	}
	vi sm;
	sm.push_back(0);
	for (int i = 1; i < f.size(); i++) {
		if (!i)
			sm.push_back(f[i].second);
		else sm.push_back(f[i].second + sm[i-1]);
	}

	int j = 1;
	ll mx = 0;
	for (int i = 1; i < f.size(); i++) {
		while (j < f.size() && f[j].first - f[i].first < d) {

			j++;
		}
//		cout << j << endl;
		mx = max(mx, sm[j-1] - sm[i-1]);
	}
	cout << mx << endl;
	return 0;
}
