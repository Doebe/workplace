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

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

ll sum;
vector<vi> g;
vi color;

ll bicolor(int x) {
	ll c[2];
	MEM(c, 0);
	queue<int> q;
	color[x] = 0;
	c[0]++;
	q.push(x);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int j = 0; j < g[cur].size(); j++) {
			int y = g[cur][j];
			if (color[y] == -1) {
				color[y] = 1 - color[cur];
				c[color[y]]++;
				q.push(y);
			} else if (color[y] == color[cur])
				return -1;
		}
	}
	return c[0]*(c[0]-1)/2 + c[1]*(c[1]-1)/2;
}

int main() {
	ll n, m;
	cin >> n >> m;
	if (m == 0) {
		cout << 3 << " " << n * (n - 1) * (n - 2) / 6 << endl;
		return 0;
	}
	g.assign(n+1, vi());
	color.assign(n+1, -1);
	int a, b, c = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		if (g[a].size() != 0 || g[b].size() != 0)
			c = 1;
//		cout << g[a].size() << " " << g[b].size() << endl;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	if (!c) {
		cout << 2 << " " << m * (n - 2) << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (color[i] < 0 && g[i].size() > 0) {
			ll cur = bicolor(i);
			if (cur == -1) {
				cout << 0 << " " << 1 << endl;
				return 0;
			}
			sum += cur;
		}
	}
	cout << 1 << " " << sum << endl;
	return 0;
}
