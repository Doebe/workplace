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
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	vi dif;
	for (int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		dif.push_back(temp);
	}
	sort(dif.begin(), dif.end());
	vector<pair<vi, ll> > p;
	int ans = 0;
	for (int i = 0; i < n; i++){
		int cursize = p.size();
		for (int j = 0; j < cursize; j++){
			vi newvi = p[j].first;
			newvi.push_back(dif[i]);
			ll newsum = p[j].second + dif[i];
			if (newsum >= l && newsum <= r && dif[i]-newvi[0] >= x)
				ans++;
			p.push_back(make_pair(newvi, newsum));
		}
		p.push_back(make_pair(vi(1, dif[i]), dif[i]));
	}
	cout << ans << endl;
	return 0;
}
