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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<double, ii> di;
typedef vector<di> vdi;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int p, t, n;
	scanf("%d", &p);
	while (p--) {
		scanf("%d %d", &t, &n);
//		vi num;
//		num.push_back(1);
//		int s;
		vdi num;
		num.push_back(di(0, ii(0,1)));
//		for (int i = 1; i <= n/2; i++) {
//			for (int j = n; j > i; j--) {
//				if (gcd(i, j) != 1)
//					continue;
//				num.push_back(di((double)i/j, j));
//			}
//		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				if (gcd(i, j) != 1)
					continue;
				num.push_back(di((double)j/i, ii(j, i)));
			}
		}
		sort(num.begin(), num.end());
		num.push_back(di(1, ii(1,1)));
//		for (int i = 1; i <= n/2; i++) {
//			for (int j = n; j > n*i/(i+1); j--) {
//				num.push_back(j/gcd(j, i));
//				if (j/gcd(j, i) == 2) {
//					s = num.size();
//					break;
//				}
//			}
//		}
		for (int i = 0; i < num.size(); i++)
			cout << num[i].second.first << "/" << num[i].second.second << " ";
		cout << endl;
//		for (int i = s-2; i >= 0; i--)
//			num.push_back(num[i]);
//		for (int i = 0; i < num.size(); i++)
//			cout << num[i] << " ";
//		cout << endl;
//		ii cur(0, 0);
//		for (int i = 0; i < num.size()-1; i++) {
//			if (i == 0) {
//				cur = ii(num[i].second, num[i+1].second);
//				continue;
//			}
////			cur = ii(cur.first*num[i+1].second+num[i].second*cur.second, cur.second*num[i+1].second);
//			cur = ii(cur.first*num[i+1].second+num[i].second*cur.second, cur.second*num[i+1].second);
//			ll g = gcd(cur.first, cur.second);
//			cur.first/=g;
//			cur.second/=g;
//		}
//		printf("%d %lld/%lld\n", t, cur.first, cur.second);
	}
	return 0;
}
