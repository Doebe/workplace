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

class V {
public:
	int lvl;
	int index;
	int parents;

	V(int _l, int _index) : lvl(_l), index(_index){};
};

int main(){
	int n, m;
	cin >> n >> m;
	vector<V> all;
	for (int i = 0; i < n; i++)
		all.push_back(V(1, i));
	map<int, vector<V> > nodes;
	nodes[1] = vector<V>();
	nodes[1].push_back(all[0]);
	int p;
	int mxlvl = 0;
	for (int i = 1; i <= n-1; i++) {
		cin >> p;
		p--;
		all[i].parents = p;
		all[i].lvl = all[p].lvl + 1;
		nodes[all[i].lvl].push_back(all[i]);
		mxlvl = max(mxlvl, all[i].lvl);
	}
	map<int, vector<vi> > ans;
	for (int i = mxlvl; i >= 1; i--) {
		for (int j = 0; j < nodes[i].size(); j++) {
			V cur = nodes[i][j];
			if (i == mxlvl)
				ans[i][cur.index] = vi(26, 0);
			ans[i][cur.index][line[cur.index]-'a']++;
		}
	}

	string line;
	getline(cin, line);
	getline(cin, line);

//	for (map<int, vector<V> >::iterator it = nodes.begin(); it != nodes.end(); it++) {
//		cout << it->first << ": ";
//		for (int i = 0; i < it->second.size(); i++)
//			cout << it->second[i].index << " ";
//		cout << endl;
//	}

	int v, h;
	while (m--) {
		cin >> v >> h;
		v--;
		int alpha[26];
		MEM(alpha, 0);
		for (int i = 0; i < nodes[h].size(); i++) {
			V cur = nodes[h][i];
			if (cur.parents.count(v) || cur.index == v)
				alpha[line[cur.index]-'a']++;
		}
		bool yes = true;
		int odd  = 0;
		for (int i = 0; i < 26; i++)
//			cout << alpha[i] << " ";
//		cout << endl;
			if (alpha[i] % 2)
				odd++;
		if (odd > 1)
			yes = false;
		if (yes)
			printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
