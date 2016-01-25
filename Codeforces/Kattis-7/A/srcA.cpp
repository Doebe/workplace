#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define MAXLOG 30
vector<vii> G;
vector<string> S;
vi taken;
vi vals;
int L, l;
int n;

map<char, int> F;
map<int, char> F2;
vi zr;
int ans;
map<char, ll> co;


void solve() {

	if (vals.size() == L) {
		map<int, int> F2;

//	for (int i = 0; i < vals.size(); ++i) {
//	F2[i] = vals[i];
//	}
//	for (int i = 0; i < l; ++i) {
//	int s = 0;
//	for (int j = 0; j < n-1; ++j) {
//	s += F2[F[S[j][i]]];
//	}
//	int a = F2[F[S[n-1][i]]];
//
//	if(s != a)return;
//	}
//
//	printf("ans = %d\n",ans);
//		ans++;
//		return;
//	}
		ll num = 0;
		for (map<char, ll>::iterator it = co.begin(); it != co.end(); it++) {
			num += it->second * vals[F[it->first]];
		}
		if (num == 0) {
			ans++;
			for (map<char, ll>::iterator it = co.begin(); it != co.end(); it++) {
//				cout << it->first << " " << vals[F[it->first]] << endl;
			}
		}
		return;
	}

	int up = 0;
	if (zr[F2[vals.size()]-'A'] == 1)
		up = 1;
	for (int i = up; i < 10; ++i) {
		if (!taken[i]) {
			taken[i] = 1;
			vals.push_back(i);
			solve();
			vals.pop_back();
			taken[i] = 0;
		}
	}
}

int main() {

	cin >> n;
	l = 100;
	S.assign(n, "");
	zr.assign(26, 0);
	taken.assign(100, 0);
//	for (char c = 'A'; c <= 'Z'; c++)
//		co[c] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
		reverse(S[i].begin(), S[i].end());
		if (i < n-1)
			for (int j = 0; j < S[i].size(); j++) {
				co[S[i][j]] += pow(10, j);
			}
		else
			for (int j = 0; j < S[i].size(); j++) {
				co[S[i][j]] -= pow(10, j);
			}
		zr[S[i][S[i].size()-1]-'A'] = 1;
		l = min(l, (int) S[i].size());
	}
	L = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < S[i].size(); ++j) {
			if (!F.count(S[i][j])) {
				F[S[i][j]] = L;
				F2[L] = S[i][j];
				L = F.size();
			}
		}
	}
//	printf("L = %d\n", L);

//	for (map<char, ll>::iterator it = co.begin(); it != co.end(); it++)
//		cout << it->first << ": " << it->second << endl;

	ans = 0;
	solve();
	cout << ans << endl;

}
