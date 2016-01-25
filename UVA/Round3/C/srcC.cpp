// 12398

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

int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, -1, 0, 1};
vii pos;

int main(){
	string s;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			pos.push_back(ii(i, j));
	int c = 0;
	while (getline(cin, s)) {
//		cout << s << endl;
		c++;
		cout << "Case #" << c << ":" << endl;
		int grid[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		for (int i = 0; i < s.size(); i++) {
			int x = pos[s[i]-'a'].first;
			int y = pos[s[i]-'a'].second;
			grid[x][y]++;
			grid[x][y] %= 10;
			for (int j = 0; j < 4; j++) {
				int nx = x + xx[j];
				int ny = y + yy[j];
				if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)
					continue;
				grid[nx][ny]++;
				grid[nx][ny] %= 10;
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0;j  < 3; j++) {
				cout << grid[i][j];
				if (j < 2)
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
