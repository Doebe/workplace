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
	ll h, n;
	cin >> h >> n;

	ll l = pow(2, h);
	ll low = 1, high = l;
	ll node = 0;
	int flag = 0;
	while (low < high){
		ll mid = (high + low) / 2;
//		if (n == mid){
//
//		}
		if (n > mid){
			if (!flag){
				node += l;
				l /= 2;
			}else{
				node += 1;
				l /= 2;
				flag = 1 - flag;
			}
			low = mid + 1;
		} else {
			if (flag){
				node += l;
				l /= 2;
			}else{
				node += 1;
				l /= 2;
				flag = 1 - flag;
			}
			high = mid;
		}
	}
//	ll node = 0;
	cout << node << endl;
//	n = l / 2 + n - 1;
//	ll tree[l];
//	MEM(tree, 0);
//	int flag = 0; // left
//	ll target = 1;
//	ll node = 0;
//	while (target != n){
//		if (!tree[target]){
//			tree[target] = 1;
//			node++;
//		}
//		if (!flag){
//			if (target*2 >= l || tree[target*2] == 1)
//				target /= 2;
//			else {
//				target *= 2;
//				flag = 1 - flag;
//			}
//		}else{
//			if (target*2+1 >= l || tree[target*2+1] == 1)
//				target /= 2;
//			else {
//				target = target * 2 + 1;
//				flag = 1 - flag;
//			}
//		}
//	}
}
