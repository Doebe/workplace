// 871

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

char grid[27][27];
int r, c, mx, cur;

int xx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(int i, int j) {
	grid[i][j] = '2';
	cur++;
	for (int a = 0; a < 8; a++) {
		int ni = i + xx[a];
		int nj = j + yy[a];
		if (ni < 0 || ni >= r || nj < 0 || nj >= c)
			continue;
		if (grid[ni][nj] == '1')
			dfs(ni, nj);
	}
}

int main(){
	int n;
	cin >> n;
	string line;

	getline(cin, line);
	getline(cin, line);
	while (n--) {
		r = 0;
		c = 0;
		while (getline(cin, line) && line != "") {
			c = line.size();
			for (int i = 0; i < c; i++)
				grid[r][i] = line[i];
			r++;
		}
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				cout << grid[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << r << " " << c << endl;
		mx = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (grid[i][j] == '1') {
					cur = 0;
					dfs(i, j);
					mx = max(mx, cur);
				}
			}
		}
		cout << mx << endl;
		if (n > 0)
			cout << endl;
//		for (int i = 0; i < r; i++) {
//			for (int j = 0; j < c; j++) {
//				cout << grid[i][j] << " ";
//			}
//			cout << endl;
//		}
	}
	return 0;
}
