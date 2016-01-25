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

int L, U, R;

int main(){
	int c = 0;
	while (cin >> L >> U >> R){
		if (!L && !U && !R)
			break;
		vi numbers; int num;
		for (int i = 0; i < R; i++) {
			cin >> num;
			numbers.push_back(num);
		}
		vi dist(10000, INF);
		dist[L] = 0;
		queue<int> q; q.push(L);
		int d = -1;
		while (!q.empty()){
			int u = q.front(); q.pop();
			for (int i = 0; i < R; i++){
				int v = (u + numbers[i]) % 10000;
				if (dist[v] == INF){
					dist[v] = dist[u] + 1;
					if (v == U % 10000){
						d = dist[v];
						break;
					}
					q.push(v);
				}
			}
			if (d > 0)
				break;
		}
//		for (int i = 0; i < 10000; i++)
//			cout << dist[i] << " ";
		printf("Case %d: ", ++c);
		if (d < 0)
			printf("Permanently Locked\n");
		else printf("%d\n", d);
	}
}
