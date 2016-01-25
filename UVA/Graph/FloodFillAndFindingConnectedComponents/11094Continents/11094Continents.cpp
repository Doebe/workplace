#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int NEG_INF = -1000000000;

#define max(a,b)((a)>(b)?(a):(b))
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

int M, N, X, Y;
char m[21][21];
int r[] = {1, 0, -1, 0};
int c[] = {0, 1, 0, -1};

void dfs(int x, int y, char a, char b){
	if (y < 0) y = N - 1;
	if (y >= N) y = 0;
	if (x < 0 || x >= M) return;
	if (m[x][y] != a) return;
	m[x][y] = b;
	for (int i = 0; i < 4; i++)
		dfs(x + r[i], y + c[i], a, b);
}

int floodfill(int x, int y, char a, char b){
	if (y < 0) y = N - 1;
	if (y >= N) y = 0;
	if (x < 0 || x >= M) return 0;
	if (m[x][y] != a) return 0;
	m[x][y] = b;
	int ans = 1;
	for (int i = 0; i < 4; i++){
		ans += floodfill(x + r[i], y + c[i], a, b);
	}
	return ans;
}

int main(){
	while (cin >> M >> N){
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				cin >> m[i][j];
		cin >> X >> Y;
		char a = m[X][Y];
		char b = 'a';
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				if (m[i][j] != a)
					b = m[i][j];
		dfs(X, Y, a, b);
//		for (int i = 0; i < M; i++){
//			for (int j = 0; j < N; j++)
//				cout << m[i][j];
//			cout << endl;
//		}
		int mx = 0;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++){
				int ans = floodfill(i, j, a, b);
				mx = max(mx, ans);
			}
		cout << mx << endl;
	}
	return 0;
}
