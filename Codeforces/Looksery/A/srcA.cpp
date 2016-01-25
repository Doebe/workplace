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

int main(){
	int n, m;
	cin >> n >> m;
	char adj[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> adj[i][j];
	int cnt = 0;
	for (int i = 0; i < n-1; i++){
		for (int j = 0; j < m-1; j++){
			char cur = adj[i][j];
			char right = adj[i][j+1];
			char down = adj[i+1][j];
			char rightd = adj[i+1][j+1];
			vector<char> l;
			l.push_back(cur);
			l.push_back(right);
			l.push_back(down);
			l.push_back(rightd);
			sort(l.begin(), l.end());
			if (l[0] == 'a' && l[1] == 'c' && l[2] == 'e' && l[3] == 'f')
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
