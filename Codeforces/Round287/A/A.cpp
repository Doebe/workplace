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
	int n, k;
	scanf("%d %d", &n, &k);
	map<int, int> m;

	priority_queue<ii> pq;
	for (int i = 1; i<=n; i++){
		int a;
		scanf("%d", &a);
		m[i] = a;
		pq.push(ii(-a, i));
	}
	int cnt = 0;
	vii ans;
	while (!pq.empty()){
		ii fr = pq.top(); pq.pop();
		int f = -fr.first;
		if (k < f)
			break;
		k -= f;
		ans.push_back(fr);
		cnt++;
	}
	printf("%d\n", cnt);
	if (cnt > 0){
		for (int i = 0; i < cnt-1;i++)
			printf("%d ", ans[i].second);
		printf("%d\n", ans[cnt-1].second);
	}
}
