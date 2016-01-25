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

map<iii, int> visit;

bool istriangle(int a, int b, int c) {
	if (a + b <= c || a + c <= b || b + c <= a)
		return false;
	if (abs(a - b) >= c || abs(a - c) >= b || abs(b - c) >= a)
		return false;
	return true;
}

int main(){
	int s[3], l;
	cin >> s[0] >> s[1] >> s[2] >> l;
	ll ans = 0;
	int tol, tos, tor, total, dif;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < 3; j++) {
			total = s[(j+1)%3] + s[(j+2)%3];
			dif = abs(s[(j+1)%3] - s[(j+2)%3]);
			if (total % 2 == 0) {
				tol = (i + total - s[j] - 1) / 2 - 1;
			}
			else {
				tol = (i + total - s[j] - 1) / 2;
				tos = (i + dif - s[j] - 1) / 2 + 1;
			}
			cout << tos << " " << tol << endl;
//			tor = total / 2 - s[(j+1)%3] - s[(j+2)%3];
			if (tol >= 0 && tos >= 0)
				ans += (tol - tos);
		}
	}
	cout << ans << endl;



//	for (int i = 0; i <= l; i++) {
//		for (int j = 0; j <= l - i; j++) {
//			if (a + b + i < c + j)
//				break;
//			if (!istriangle(a, b+i, c+j))
//				continue;
//			iii cur(a, ii(b+i, c+j));
//			if (visit.count(cur))
//				continue;
////			cout << "in a : " << a << " " << b+i << " " << c+j << endl;
//			visit[cur] = 1;
//			ans += l / 3 + 1;
//		}
//	}
//	for (int i = 0; i <= l; i++) {
//		for (int j = 0; j <= l - i; j++) {
//			if (a + c + i < b + j)
//				break;
//			if (!istriangle(a+i, b+j, c))
//				continue;
//			iii cur(a+i, ii(b+j, c));
//			if (visit.count(cur))
//				continue;
////			cout << "in a : " << a+i << " " << b+j << " " << c << endl;
//			visit[cur] = 1;
//			ans += l / 3 + 1;
//		}
//	}
//	for (int i = 0; i <= l; i++) {
//		for (int j = 0; j <= l - i; j++) {
//			if (b + c + i < a + j)
//				break;
//			if (!istriangle(a+j, b, c+i))
//				continue;
//			iii cur(a+j, ii(b, c+i));
//			if (visit.count(cur))
//				continue;
////			cout << "in a : " << a+j << " " << b << " " << c+i << endl;
//			visit[cur] = 1;
//			ans += l / 3 + 1;
//		}
//	}
//	cout << ans << endl;
	return 0;
}
