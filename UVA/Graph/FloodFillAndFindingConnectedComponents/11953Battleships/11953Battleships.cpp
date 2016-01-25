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

int T, N, rst;
char m[102][102];
char ship = 'x', hit = '@', empty = '.';
int r[] = {1, 0, -1, 0};
int c[] = {0, 1, 0, -1};

bool dfs(int x, int y){
//	cout << m[x][y] << endl;
	if (x < 0 || x >= N || y < 0 || y >= N || m[x][y] == empty) return false;
	bool alive = false;
	if (m[x][y] == hit){
		m[x][y] = empty;
		for (int i = 0; i < 4; i++){
			bool next = dfs(x + r[i], y + c[i]);
			alive = alive || next;
		}
		return alive;
	}
	m[x][y] = empty;
	alive = true;
	for (int i = 0; i < 4; i++){
		bool next = dfs(x + r[i], y + c[i]);
		alive = alive || next;
//		cout << m[x + r[i]][y + c[i]] << endl;
	}
	return alive;
}

int main(){
	cin >> T;
	for (int k = 0; k < T; k++){
		cin >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> m[i][j];
		int rst = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++){
				if (m[i][j] == empty)
					continue;
				if (dfs(i, j))
					rst++;
//				for (int i = 0; i < N; i++){
//					for (int j = 0; j < N; j++)
//						cout << m[i][j];
//					cout << endl;
//				}
			}

		cout << "Case " << k+1 << ": " << rst << endl;
	}
	return 0;
}
