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
	int n, s, p, v;
	char a;
	map<int, int> B;
	map<int, int> S;
	cin >> n >> s;
	while (n--) {
		cin >> a >> p >> v;
		if (a == 'B') {
			if (!B.count(p))
				B[p] = 0;
			B[p] += v;
		} else {
			if (!S.count(p))
				S[p] = 0;
			S[p] += v;
		}
	}
	vii BB, SS;
	vector<pair<char, ii> > ans;
	for (map<int, int>::iterator it = B.begin(); it!=B.end(); it++)
		BB.push_back(ii(it->first, it->second));
	for (map<int, int>::iterator it = S.begin(); it!=S.end(); it++)
		SS.push_back(ii(it->first, it->second));
	sort(BB.begin(), BB.end());
	sort(SS.begin(), SS.end());

	int x = s;
	for (int i = 0; i < SS.size() && x > 0; i++) {
		ans.insert(ans.begin(), make_pair('S', SS[i]));
		x--;
	}
	x = s;
	for (int i = BB.size() - 1; i >= 0 && x > 0; i--) {
		ans.push_back(make_pair('B', BB[i]));
		x--;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << endl;
	return 0;
}
