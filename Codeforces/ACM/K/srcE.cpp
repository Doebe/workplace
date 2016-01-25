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
	int t, n, k;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &k);
		int num[n];
		for (int i = 0; i < n; i++)
			scanf("%d", &num[i]);
		sort(num, num+n);
		int i = 0, j = n-1;
		int x = -1, y = -1;
		while (i < j) {
			if (num[i] * num[j] == k) {
				x = num[i];
				y = num[j];
				break;
			}
			if (num[i] * num[j] > k)
				j--;
			else i++;
		}
		if (x == -1)
			printf("%d\n", -1);
		else printf("%d %d\n", num[i], num[j]);
	}
	return 0;
}
