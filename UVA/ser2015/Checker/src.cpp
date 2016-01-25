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
typedef pair<ii,int> iii;
typedef vector<iii> viii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

list<ii> cyc;
list<ii> cyc2;
map<ii, viii> adj;
int xx[4] = {-1, 1, 1, -1};
int yy[4] = {-1, -1, 1, 1};
int n, grid[26][26];

void EulerTour(list<ii>::iterator i, ii u) {
//	cout << u.first << " " << u.second << endl;
//	cout << adj[u].size() << endl;
	for (int j = 0; j < adj[u].size(); j++) {
		iii &v = adj[u][j];
//		if (u == ii(2,8))
//			printf("v = (%d %d)\n", v.first.first, v.first.second);
//		cout << v.first.first << " " << v.first.second << endl;
		if (v.second == 1) {
			v.second = 0;
//			cout << u << " " << v.first << " " << adj[u][j].second.second << ": ";
			for (int k = 0; k < adj[v.first].size(); k++) {
				iii &uu = adj[v.first][k];
				if (uu.first == u && uu.second == 1) {
//					cout << uu.first << endl;
					uu.second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(i, v.first), v.first);
			break;
		}
	}
}

void EulerTour2(list<ii>::iterator i, ii u) {
//	cout << u.first << " " << u.second << endl;
//	cout << adj[u].size() << endl;
	for (int j = 0; j < adj[u].size(); j++) {
		iii &v = adj[u][j];
//		printf("v = (%d %d: %d)\n", v.first.first, v.first.second, v.second);
		if (v.second == 1) {
			v.second = 0;
//			cout << u << " " << v.first << " " << adj[u][j].second.second << ": ";
			for (int k = 0; k < adj[v.first].size(); k++) {
				iii &uu = adj[v.first][k];
				if (uu.first == u && uu.second == 1) {
//					cout << uu.first << endl;
					uu.second = 0;
					break;
				}
			}
			EulerTour2(cyc2.insert(i, v.first), v.first);
		}
	}
}

bool check(int a, int b) {
	if (a < 0 || a >= n || b < 0 || b >= n)
		return false;
	return true;
}

int main(){
	cin >> n;
	char c;
	int total = 0;
	vii black;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (c == 'W') {
				grid[i][j] = 0;
				total++;
			}
			else if (c == 'B') {
				grid[i][j] = 1;
				black.push_back(ii(i, j));
			}
			else
				grid[i][j] = 2;
		}
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++)
//			cout << grid[i][j] << " ";
//		cout << endl;
//	}
	adj.clear();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 0) {
				for (int k1 = 0; k1 < 4; k1++) {
					int k2 = (k1+2)%4;
					int i1 = i + xx[k1];
					int j1 = j + yy[k1];
					int i2 = i + xx[k2];
					int j2 = j + yy[k2];
					if (!check(i1, j1) || !check(i2, j2))
						continue;
					if (grid[i2][j2] == 2 && grid[i1][j1] != 0) {
						if (!adj.count(ii(i1, j1)))
							adj[ii(i1, j1)] = viii();
						adj[ii(i1, j1)].push_back(iii(ii(i2, j2), 1));
					}
					if (grid[i2][j2] == 1 && grid[i1][j1] != 0) {
						if (!adj.count(ii(i1, j1)))
							adj[ii(i1, j1)] = viii();
						adj[ii(i1, j1)].push_back(iii(ii(i2, j2), -1));
					}
				}
			}
		}
	int ans = 0;
	for (int b = 0; b < black.size(); b++) {
		for (map<ii, viii>::iterator it = adj.begin(); it != adj.end(); it++) {
//			printf("(%d,%d): ", it->first.first, it->first.second);
			for (int i = 0; i < it->second.size(); i++) {
				if (it->second[i].second == 0)
					it->second[i].second = 1;
//				printf("(%d %d) ", it->second[i].first.first, it->second[i].first.second);
			}
//			printf("\n");
		}
		for (int i = 0; i < adj[black[b]].size(); i++) {
			ii tmp = adj[black[b]][i].first;
			for (int j = 0; j < adj[tmp].size(); j++)
				if (adj[tmp][j].first == black[b])
					adj[tmp][j].second = 1;
		}
		int num = 0;
		cyc.clear();
		cyc.insert(cyc.begin(), black[b]);
		EulerTour(cyc.begin(), black[b]);
		num = cyc.size()-1;

		// debug
//		if (b == 0) {
//			printf("path: ");
//			for (list<ii>::reverse_iterator it = cyc.rbegin(); it != cyc.rend(); it++) {
//				if (it != cyc.rbegin())
//					printf(" ");
//				printf("(%d %d)", it->first, it->second);
//			}
//			printf("\n");
//			printf("%d, %d\n", num, total);
//		}

		if (num == total) {
			ans++;
			for (int i = 0; i < adj[black[b]].size(); i++) {
				ii tmp = adj[black[b]][i].first;
				for (int j = 0; j < adj[tmp].size(); j++)
					if (adj[tmp][j].first == black[b])
						adj[tmp][j].second = -1;
			}
			continue;
		}
		for (list<ii>::iterator it = cyc.begin(); it != cyc.end(); it++) {
			cyc2.clear();
			cyc2.insert(cyc2.begin(), *it);
			EulerTour2(cyc2.begin(), *it);

//			// debug
//			if (b == 0) {
//				printf("path: ");
//				for (list<ii>::reverse_iterator it = cyc2.rbegin(); it != cyc2.rend(); it++) {
//					if (it != cyc2.rbegin())
//						printf(" ");
//					printf("(%d %d)", it->first, it->second);
//				}
//				printf("\n");
//			}

			if (cyc2.size() == 1)
				continue;
			if (*(cyc2.begin()) == *(cyc2.rbegin())) {
				num += cyc2.size()-1;
				if (num == total) {
					ans++;
					break;
				}
			} else {
				ans = 0;
				break;
			}
		}
		for (int i = 0; i < adj[black[b]].size(); i++) {
			ii tmp = adj[black[b]][i].first;
			for (int j = 0; j < adj[tmp].size(); j++)
				if (adj[tmp][j].first == black[b])
					adj[tmp][j].second = -1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
