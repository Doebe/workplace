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

int n, V, s, t;
int main(){
	int c = 0;
	scanf("%d\n\n", &n);
	while (n--){
		string str;
		map<int, string> m1;
		map<string, int> m2;
		while (getline(cin, str)){
			if (str == "*")
				break;
			m2[str] = m1.size();
			m1[m2[str]] = str;
		}
		int adj[m1.size() + 2][m1.size() + 2];
		MEM(adj, 0);
		for (int i = 0; i < m1.size(); i++){
			for (int j = i; j < m1.size(); j++){
				if (m1[i].size() != m1[j].size() || i == j)
					continue;
				int cnt = 0; bool conn = true;
				for (int k = 0; k < m1[i].size(); k++)
					if (m1[i][k] != m1[j][k])
						if (++cnt > 1){
							conn = false;
							break;
						}
				if (conn)
					adj[i][j] = adj[j][i] = 1;
			}
		}
//		for (int i = 0; i < m1.size(); i++){
//			for (int j = 0; j < m1.size(); j++)
//				cout << adj[i][j] << " ";
//			cout << endl;
//		}
		if (++c > 1)
			cout << endl;
		while (getline(cin, str)){
			if (str == "")
				break;
			stringstream ss; ss.str(str);
			string a, b;
			ss >> a; ss >> b;
			s = m2[a]; t = m2[b];
			vi dist(m1.size(), INF);
			dist[s] = 0;
			queue<int> q; q.push(s);
			while (!q.empty()){
				int u = q.front(); q.pop();
				for (int v = 0; v < m1.size(); v++){
					if (adj[u][v] == 1 && dist[v] == INF){
						dist[v] = dist[u] + 1;
						q.push(v);
					}
				}
			}
			printf("%s %s %d\n", a.c_str(), b.c_str(), dist[t]);
		}
	}
	return 0;
}
