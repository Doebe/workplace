// 10189

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

int xx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int yy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

int main(){
	int n, m, c  = 0;;
	while (cin >> n >> m && n && m) {
		c++;
		char grid[n][m];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> grid[i][j];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == '*') {
					for (int a = 0; a < 8; a++) {
						int ni = i + xx[a];
						int nj = j + yy[a];
						if (ni < 0 || ni >= n || nj < 0 || nj >= m)
							continue;
						if (grid[ni][nj] == '.')
							grid[ni][nj] = '1';
						else if (grid[ni][nj] == '*')
							continue;
						else grid[ni][nj]++;
					}
				} else if (grid[i][j] == '.')
					grid[i][j] = '0';
		if (c > 1)
			cout << endl;
		cout << "Field #" << c << ":" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << grid[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
