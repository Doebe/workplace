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

int P, R, adj[52][52];
map<int, string> mis;
map<string, int> msi;

int main(){
	int cnt = 0;
	while (cin >> P >> R){
		if (P == 0)
			break;
		for (int i = 0; i < 52; i++)
			for (int j = 0; j < 52; j++)
				adj[i][j] = 100;
		mis.clear();
		msi.clear();
		string a, b;
		for (int r = 0; r < R; r++){
			cin >> a >> b;
			if (!msi.count(a)){
				msi[a] = mis.size();
				mis[msi[a]] = a;
			}
			if (!msi.count(b)){
				msi[b] = mis.size();
				mis[msi[b]] = b;
			}
			adj[msi[a]][msi[b]] = 1;
			adj[msi[b]][msi[a]] = 1;
		}

		for (int k = 0; k < P; k++)
			for (int i = 0; i < P; i++)
				for (int j = 0; j < P; j++)
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

		int m = 0;
		bool c = true;
		for (int i = 0; i < P; i++){
			for (int j = 0; j < P; j++){
				if (i == j)
					continue;
				if (adj[i][j] == 100){
					c = false;
					break;
				}
				m = max(m, adj[i][j]);
			}
			if (c == false)
				break;
		}
		printf("Network %d: ", ++cnt);
		if (c)
			cout << m << endl;
		else cout << "DISCONNECTED" << endl;
		cout << endl;
	}
	return 0;
}
