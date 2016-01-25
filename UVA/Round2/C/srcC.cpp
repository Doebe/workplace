// 302

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
typedef pair<int,ii> iii;
typedef vector<iii> viii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

list<int> cyc;
map<int, viii> adj;

void EulerTour(list<int>::iterator i, int u) {
	for (int j = 0; j < adj[u].size(); j++) {
		ii &v = adj[u][j].second;
//		cout << u << " " << v.first << " " << adj[u][j].second.second << endl;
		if (v.second) {
			v.second = 0;
//			cout << u << " " << v.first << " " << adj[u][j].second.second << ": ";
			for (int k = 0; k < adj[v.first].size(); k++) {
				ii &uu = adj[v.first][k].second;
				if (uu.first == u && uu.second) {
//					cout << uu.first << endl;
					uu.second = 0;
					break;
				}
			}
			EulerTour(cyc.insert(i, adj[u][j].first), v.first);
		}
	}
}

int main(){
	int x, y, z;
	while (cin >> x >> y && x && y) {
		cin >> z;
		int stt;
		stt = min(x, y);
		adj.clear();
		if (!adj.count(x))
			adj[x] = viii();
		if (!adj.count(y))
			adj[y] = viii();
		adj[x].push_back(iii(z, ii(y, 1)));
		adj[y].push_back(iii(z, ii(x, 1)));
		while (cin >> x >> y && x && y) {
			cin >> z;
			if (!adj.count(x))
				adj[x] = viii();
			if (!adj.count(y))
				adj[y] = viii();
			adj[x].push_back(iii(z, ii(y, 1)));
			adj[y].push_back(iii(z, ii(x, 1)));
		}
		int poss = 1;
		for (map<int, viii>::iterator it = adj.begin(); it != adj.end(); it++) {
			sort(it->second.begin(), it->second.end());
			if (it->second.size() % 2) {
				poss = 0;
				break;
			}
		}
		if (!poss) {
			cout << "Round trip does not exist." << endl;
			cout << endl;
			continue;
		}
//		for (map<int, viii>::iterator it = adj.begin(); it != adj.end(); it++) {
//			cout << it->first << ": ";
//			for (int i = 0; i < it->second.size(); i++) {
//				cout << "(" << it->second[i].first << " " << it->second[i].second.first << " " << it->second[i].second.second << ") ";
//			}
//			cout << endl;
//		}
		cyc.clear();
		EulerTour(cyc.begin(), stt);
		for (list<int>::reverse_iterator it = cyc.rbegin(); it != cyc.rend(); it++) {
			if (it != cyc.rbegin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
		cout << endl;
	}
	return 0;
}
