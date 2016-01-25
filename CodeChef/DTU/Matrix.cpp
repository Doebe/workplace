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
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<ll> vi;
typedef vector<ii> vii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

int main() {
	int n, m;
	cin >> n >> m;
	int B[n][m], A[n][m], C[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> B[i][j];
	MEM(A, 0);
	MEM(C, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (B[i][j] == 0)
				continue;
			for (int k = 0; k < n; k++){
				A[k][j] = 1;
				C[k][j] = 1;
			}
			for (int k = 0; k < m; k++){
				A[i][k] = 1;
				C[i][k] = 1;
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 1)
				continue;
			for (int k = 0; k < n; k++)
				C[k][j] = 0;
			for (int k = 0; k < m; k++)
				C[i][k] = 0;
		}
	int yes = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (B[i][j] == C[i][j])
				continue;
			yes = 0;
			break;
		}
		if (!yes)
			break;
	}
	if (yes)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
