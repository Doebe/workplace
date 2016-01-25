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

int r, c, grid[1005][1005], hor[] = {-1, 0, 1, 0}, ver[] = {0, -1, 0, 1};

bool valid(int x, int y){
	return x >= 0 && x < c && y >= 0 && y < r && grid[x][y] == 0;
}

vector<vi> adj;
int main(){
	int b, l, n, p;
	while (cin >> r >> c){
		if (r == 0)
			break;
		MEM(grid, 0);
		cin >> b;
		while (b--){
			cin >> l >> n;
			while (n--){
				cin >> p;
				grid[l][p] = 1;
			}
		}
//		for (int i = 0; i < r; i++){
//			for (int j = 0; j < c; j++)
//				cout << grid[i][j] << " ";
//			cout << endl;
//		}
		int x, y;
		cin >> x >> y;
		ii s(x, y);
		cin >> x >> y;
		ii t(x, y);

		int dist[r][c];
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				dist[i][j] = -1;

		dist[s.first][s.second] = 0;
		queue<ii> q; q.push(s);
		bool found = false;
		while (!q.empty()){
			ii u = q.front(); q.pop();
			for (int i = 0; i < 4; i++){
				int u1 = u.first + hor[i], u2 = u.second + ver[i];
//				cout << u1 << " " << u2 << endl;
				if (valid(u1, u2) && dist[u1][u2] == -1){
					dist[u1][u2] = dist[u.first][u.second] + 1;
					q.push(ii(u1, u2));
					if (u1 == t.first && u2 == t.second){
						found = true;
						break;
					}
				}
			}
			if (found)
				break;
		}
//		cout << endl;
//		for (int i = 0; i < r; i++){
//			for (int j = 0; j < c; j++)
//				cout << dist[i][j] << " ";
//			cout << endl;
//		}
		cout << dist[t.first][t.second] << endl;
	}
	return 0;
}
