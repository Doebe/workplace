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
	int k;
	cin >> k;
	if ((k - 1) % 2 == 1)
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		int n = (2*(k-1)+1) * 2;
		int m = n * k / 2;
		cout << n << " " << m << endl;
		vector<vi> adj(n+1, vi());
		adj[1].push_back(2*k);
		for (int i = 2; i <= k; i++){
			adj[1].push_back(i);
		}
		for (int i = k + 1; i < 2*k; ){
			adj[i].push_back(i+1);
			i+=2;
		}
		for (int i = k + 1; i < 2*k; i++){
			for (int j = 2; j <= k; j++){
				adj[i].push_back(j);
			}
		}
		for (int i = 2*k+1; i <= 3*k-1; i++){
			adj[2*k].push_back(i);
		}
		for (int i = 3*k; i <= n;){
			adj[i].push_back(i+1);
			i+=2;
		}
		for (int i = 3*k; i <= n; i++){
			for (int j = 2*k+1; j <= 3*k-1; j++)
				adj[i].push_back(j);
		}

		for (int i = 0; i < adj.size(); i++){
			for (int j = 0; j < adj[i].size(); j++){
				cout << (i) << " " << (adj[i][j]) << endl;
			}
		}
	}
	return 0;
}
