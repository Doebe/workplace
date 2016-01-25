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
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	int adj[n+1][m+1];
	map<int, int> score;
	for (int i = 1; i <= n; i++){
		int temp = 0;
		for (int j = 1; j <= m; j++){
			scanf("%d", &adj[i][j]);
			if (adj[i][j] == 1)
				temp++;
			else
				temp = 0;
			score[i] = max(score[i], temp);
		}
	}
	int a, b;
	while(q--){
		scanf("%d %d", &a, &b);
		adj[a][b] = 1 - adj[a][b];
		int longest = 0;
		int temp = 0;
		for (int j = 1; j <= n; j++){
			if (adj[a][j] == 1)
				temp++;
			else
				temp = 0;
			longest = max(longest, temp);
		}
		score[a] = longest;
		int maxi = 0;
		for (int j = 1; j <= n; j++)
			maxi = max(maxi, score[j]);
		cout << maxi << endl;
	}
}
