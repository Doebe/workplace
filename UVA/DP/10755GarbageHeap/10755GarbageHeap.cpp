#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int NEG_INF = -1000000000;
long long inf = -2147483648LL;

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI acos(0)*2.0
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

int n, a, b, c;
ll mx;
int heap[21][21][21];

ll cnt(int x, int y, int z) {
	ll A[y+1][z+1];
	MEM(A, 0);
	ll cur = inf;
	for (int i = 1; i <= x; ++i) {
		for (int j = 1; j <= y; ++j)
			for (int k = 1; k <= z; ++k)
				A[j][k] = heap[i][j][k] + A[j][k - 1];
		ll temp[y+1];
		MEM(temp, 0);
		for (int l = 1; l <= z; ++l)
			for (int m = l; m <= z; ++m) {
				for (int j = 1; j <= y; ++j)
					temp[j] = A[j][m] - A[j][l-1] + temp[j - 1];
				for (int j = 1; j <= y; ++j)
					for (int k = j; k <= y; ++k)
						cur = max(cur, temp[k] - temp[j-1]);
			}
	}
	return cur;
}

int main() {
	cin >> n;
	MEM(heap, 0);
	while (n--) {
		cin >> a >> b >> c;
		mx = inf;
		for (int i = 1; i <= a; ++i)
			for (int j = 1; j <= b; ++j)
				for (int k = 1; k <= c; ++k)
					cin >> heap[i][j][k];
		mx = max(mx, cnt(a, b, c));
		mx = max(mx, cnt(b, a, c));
		mx = max(mx, cnt(c, a, b));
		cout << mx << endl;
	}
}
