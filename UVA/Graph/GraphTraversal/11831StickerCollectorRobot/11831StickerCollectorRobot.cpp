#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <limits>
#include <algorithm>
#include <map>
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

char grid[101][101];
map<char, pair<char, char> > mp;
int n, m, cnt;

void count(int x, int y, char d, int s) {
	//cout << x << ", " << y << endl;
	if (grid[x][y] == '*'){
		cnt++;
		grid[x][y] = '.';
	}
	if (s == 0)
		return;
	char c;
	cin >> c;
	switch (c) {
	case 'D':
		count(x, y, mp.find(d)->second.second, s-1);
		break;
	case 'E':
		count(x, y, mp.find(d)->second.first, s-1);
		break;
	case 'F':
		if (d=='N'){
			if (x == 0 || grid[x-1][y] == '#')
				count(x, y, d, s-1);
			else count(x-1, y, d, s-1);
		}
		if (d=='L'){
			if (y == m-1 || grid[x][y+1] == '#')
				count(x, y, d, s-1);
			else count(x, y+1, d, s-1);
		}
		if (d=='S'){
			if (x == n-1 || grid[x+1][y] == '#'){
				count(x, y, d, s-1);
			}
			else{
				count(x+1, y, d, s-1);
			}
		}
		if (d=='O'){
			if (y == 0 || grid[x][y-1] == '#')
				count(x, y, d, s-1);
			else count(x, y-1, d, s-1);
		}
		break;
	}
}

int main() {

	int s, stx, sty;
	char c, std;
	mp.insert(pair<char, pair<char, char> >('N', pair<char, char>('O', 'L')));
	mp.insert(pair<char, pair<char, char> >('L', pair<char, char>('N', 'S')));
	mp.insert(pair<char, pair<char, char> >('S', pair<char, char>('L', 'O')));
	mp.insert(pair<char, pair<char, char> >('O', pair<char, char>('S', 'N')));

	while (true){
		cin >> n >> m >> s;
		cnt = 0;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> grid[i][j];
				if (grid[i][j] == 'N' || grid[i][j] == 'L' || grid[i][j] == 'S'
						|| grid[i][j] == 'O') {
					stx = i;
					sty = j;
					std = grid[i][j];
				}
			}
		}

		count(stx, sty, std, s);
		cout << cnt << endl;
	}
	return 0;
}
