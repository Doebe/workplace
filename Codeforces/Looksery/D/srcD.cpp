//
#include <bits/stdc++.h>
using namespace std;

const int INF = std::numeric_limits<int>::max() / 3;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define are_equal(a,b)fabs((a)-(b))<eps
#define abs_val(a)((a)>=0)?(a):(-(a))
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}

//----------------------------------------------------------------------//
int n, m, p[100][100];
char g[100][100];

int main() {
	FASTER;
	scanf("%d %d\n", &n, &m);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++){
			cin >> g[i][j];
			p[i][j] = 1;
		}
	int cnt = 0;
	for (int i = n-1; i >= 0; i--){
		for (int j = m-1; j >= 0; j--){
			if (g[i][j] == 'W' && !p[i][j]){
				for (int k = 0; k < i; k++)
					for (int l = 0; l < j; l++)
						p[i][j] ^= 1;
				cnt++;
			}
			else if (g[i][j] == 'B' && p[i][j]){
				for (int k = 0; k < i; k++)
					for (int l = 0; l < j; l++)
						p[i][j] ^= 1;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
