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


int N;
ll ans, adj[20][20], maxi[20][20], maximum;

ll cal(int a, int b){
	if (a == N - 1)
	ll right = 0, down = 0;
	if (a + 1 >= 0 && a + 1 < N)
		right = maxi[a+1, b] ^ adj[a][b];
	if (b + 1 >= 0 && b + 1 < N)
		down = maxi[a, b+1] ^ adj[a][b];
	maxi[a][b] = max(right, down);
	maximum = max(maximum, maxi[a][b]);
	return maxi[a][b];
}

int main(){
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%lld", &adj[i][j]);
	maximum = 0;
	cal(0, 0);
	printf("%lld\n", maximum);
}
