//
#include <bits/stdc++.h>
using namespace std;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define min(a,b)(a<b?a:b)

typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//
ll x, y, d;
ii ans;

void ext(ll a, ll b) {
	if (b == 0) {
		x = 1;
		y = 0;
		d = a;
		return;
	}
	ext(b, a % b);
	ll x1 = y;
	ll y1 = x - (a / b) * y;
	x = x1;
	y = y1;
}

void updt(int x1, int y1) {
	if (x1 <= y1 && y1 > 0 && x1 > 0 && ans.second > y1) {
		ans.first = x1;
		ans.second = y1;
	} else if (x1 <= y1 && y1 > 0 && x1 > 0 && ans.second == y1 && ans.first > x1) {
		ans.first = x1;
		ans.second = y1;
	}
}

int main() {
	FASTER;
	ll t, c;
	vi fab;
	fab.push_back(1);
	fab.push_back(1);
	int i = 2;
	while (fab[i-2] + fab[i-1] <= 2000000000) {
		fab.push_back(fab[i-2]+fab[i-1]);
		i++;
	}

	cin >> t;
	while (t--) {
		cin >> c;
		ans.first = 1;
		ans.second = c-1;
		for (int i = 0; i < fab.size()-1; i++) {
			int a = fab[i];
			int b = fab[i+1];
			if (a + b > c)
			break;
			d = gcd(a, b);
			ext(a, b);
			x *= c / d;
			y *= c / d;

			int n1, n2, n3, n;

			n1 = ((double)x / (-b) );
			n2 = y / a;
			n3 = floor(((double)y - x) / (b + a));

			int x1 = x + b*n1;
			int y1 = y - a*n1;
			int x2 = x + b*n2;
			int y2 = y - a*n2;

			updt(x1, y1);
			updt(x2, y2);

			if (n3 <= max(n1, n2) && n3 >= min(n1, n2)) {
				int x3 = x + b*n3;
				int y3 = y - a*n3;
				updt(x3, y3);
			}
		}
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
