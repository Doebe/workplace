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

int DP[10010];
ii cal[5010];
int n, m, c, p, dollars, cents;
int last, fattest;

void dp(){
	for (int i = 0; i < m; i++) {
		if (DP[i] <= last)
			continue;
		last = DP[i];
		for (int j = 0; j < n; j++) {
			int cost = i + cal[j].second;
			int fat = DP[i] + cal[j].first;
			if (cost <= m && fat > DP[cost]) {
				DP[cost] = fat;
				fattest = max(fattest, fat);
			}
//			if (cal[j].second > i)
//				continue;
//			DP[i] = max(cal[j].first+DP[i-cal[j].second], DP[i]);
		}
	}
}

int main() {
	DP[0] = 0;

	while (1) {
        scanf("%d %d.%d", &n, &dollars, &cents);
        m = 100 * dollars + cents;
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n;i++) {
            scanf("%d %d.%d", &c, &dollars, &cents);
            p = 100 * dollars + cents;
			cal[i] = ii(c, p);
        }
        MEM(DP, 0);
        last = -1, fattest = 0;
        dp();
        printf("%d\n", DP[m]);
	}
//	while (scanf("%d %lf", &n, &m) && n && m) {
//		for (int i = 0; i < n; i++) {
//			scanf("%d %lf", &c, &p);
//			cal[i] = ii(c, (int)(p*100));
//			cout << i << ": " << cal[i].first << " " << cal[i].second << endl;
//		}
//		dp();
//		for (int i = 0; i <= 10; i++)
//			cout << DP[i] << " ";
//		cout << endl;
//		printf("%d\n", DP[(int)(m*100)]);
//	}
	return 0;
}
