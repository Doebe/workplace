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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<ii, ii> iiii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

int n, m, mod = 1000000;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { -1, 0, 1, 0 };
int paths[101][101][4], len[101][101][4];
queue<iiii> q;

void makemove(int i, int j, int d, iiii cur) {
	if (len[i][j][d] == 0) {
		len[i][j][d] = cur.second.second + 1;
		q.push(iiii(ii(i, j), ii(d, cur.second.second + 1)));
	}
	if (len[i][j][d] == cur.second.second + 1) {
		paths[i][j][d] += paths[cur.first.first][cur.first.second][cur.second.first];
		paths[i][j][d] %= mod;
	}
}

int main() {

	while (cin >> n >> m && n) {
		char grid[n][m];
		int si, sj, sd, ti, tj;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				cin >> grid[i][j];
				if (grid[i][j] == 'X')
					ti = i, tj = j;
				if (grid[i][j] == 'N')
					si = i, sj = j, sd = 0;
				if (grid[i][j] == 'E')
					si = i, sj = j, sd = 1;
				if (grid[i][j] == 'S')
					si = i, sj = j, sd = 2;
				if (grid[i][j] == 'W')
					si = i, sj = j, sd = 3;
			}

		MEM(paths, 0);
		MEM(len, 0);
		paths[si][sj][sd] = 1;

		iiii entry(ii(si, sj), ii(sd, 0));
		q = queue<iiii>();
		q.push(entry);
		int foundpath = INF;
		while (!q.empty()) {
			iiii cur = q.front(); q.pop();
			if (cur.second.second > foundpath)
				break;
			if (cur.first.first == ti && cur.first.second == tj)
				foundpath = cur.second.second;
//			cout << foundpath << " " << " " << cur.second.second << endl;
//			printf("foundpath : %d, i : %d, j : %d, dir : %d, dist : %d\n", foundpath, cur.first.first, cur.first.second, cur.second.first, cur.second.second);

			int newd = (cur.second.first + 1) % 4;
			makemove(cur.first.first, cur.first.second, newd, cur);

			newd = (cur.second.first + 3) % 4;
			makemove(cur.first.first, cur.first.second, newd, cur);

			int newi = cur.first.first + dx[cur.second.first];
			int newj = cur.first.second + dy[cur.second.first];

			while (0 <= newi && newi < n && 0 <= newj && newj < m
					&& grid[newi][newj] != '*') {
				makemove(newi, newj, cur.second.first, cur);
				newi += dx[cur.second.first];
				newj += dy[cur.second.first];
			}
		}

		int minlen = INF;
		for (int i = 0; i < 4; i++) {
			if (len[ti][tj][i] < minlen && len[ti][tj][i] > 0)
				minlen = len[ti][tj][i];
		}
//		cout << minlen << endl;

		int totalpaths = 0;
		for (int i = 0; i < 4; i++) {
			if (len[ti][tj][i] == minlen) {
				totalpaths += paths[ti][tj][i];
				totalpaths %= mod;
			}
		}
//		cout << totalpaths << endl;
		if (!totalpaths)
			cout << 0 << " " << 0 << endl;
		else cout << minlen << " " << totalpaths << endl;
	}
	return 0;
}
