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
typedef pair<ll, ll> ii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

ll h, q, i, l, r, a;

int main(){
	cin >> h >> q;
	vii yes, no;
	ll mxx = 1ll<<(h-1), mny = 1ll<<h;
	while (q--) {
		cin >> i >> l >> r >> a;
		l = l << (h-i);
		r = (r+1) << (h-i);
		if (a) {
			mxx = max(mxx, l);
			mny	= min(mny, r);
		}
		else no.push_back(ii(l, r));
	}
	if (mxx > mny) {
		printf("Game cheated!\n");
		return 0;
	}
	no.push_back(ii(mny, mny));
	sort(no.begin(), no.end());
	ll ans = -1;
	for (int j = 0; j < no.size(); j++) {
		ll x = no[j].first, y = no[j].second;
		if (mxx >= mny)
			break;
		if (x > mxx) {
			if (ans != -1 || x > mxx + 1) {
				printf("Data not sufficient!\n");
				return 0;
			}
			ans = mxx;
		}
		mxx = max(mxx, y);
	}
	if (ans == -1)
		printf("Game cheated!\n");
	else cout << ans << endl;
	return 0;
}
