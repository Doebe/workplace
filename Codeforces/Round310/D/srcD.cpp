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

int main() {
	int n, m, l, r, x, y, a;
	cin >> n >> m;
	vii p, d;
	for (int i = 0; i < n; ++i) {
		cin >> l >> r;
		p.push_back(ii(l, r));
		if (i == 0)
			continue;
		if (p[i - 1].second - p[i].first < 0)
			x = -(p[i - 1].second - p[i].first);
		else x = 0;
		y = max(p[i - 1].second - p[i].first,
				p[i].second - p[i - 1].first);
		d.push_back(ii(x, y));
	}
	vii q;
	for (int i = 0; i < m; i++) {
		cin >> a;
		q.push_back(ii(a, i));
	}
	sort(q.begin(), q.end());
	vii ans;
	int suc = 1;
	for (int i = 0; i < d.size(); i++) {
		int found = 0;
		for (int j = 0; j < q.size(); j++) {
			ii temp = q[j];
			int cur = temp.first;
			cout << cur << endl;
			cout << d[i].first << " " << d[i].second << endl;
			if (cur <= d[i].second && cur >= d[i].first) {
				q.erase(q.begin() + j);
				ans.push_back(temp);
				found = 1;
				break;
			}
		}
		if (!found){
			suc = 0;
			break;
		}
	}
	if (suc) {
		cout << "YES" << endl;
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i].second + 1 << " ";
		cout << endl;
	} else
		cout << "NO" << endl;

	return 0;
}
