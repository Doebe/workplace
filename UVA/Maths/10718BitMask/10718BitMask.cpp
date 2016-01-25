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
	unsigned long n, l, u, m;
	while (scanf("%lu %lu %lu", &n, &l, &u) == 3){
		bitset<32> bsn = bitset<32>(n);
		bitset<32> bsl = bitset<32>(l);
		bitset<32> bsu = bitset<32>(u);
		bitset<32> bsm = bsl;
		for (int i = 31; i >= 0; i--){
			if (!bsm[i] && !bsn[i]){
				bitset<32> temp = bsm;
				temp.flip(i);
				for (int j = i-1; j >= 0; j--)
					temp.reset(j);
				unsigned long a = temp.to_ulong();
				unsigned long b = bsl.to_ulong();
				unsigned long c = bsu.to_ulong();
				if (a >= b && a <= c)
					bsm = temp;
			}
		}
		printf("%lu\n", bsm.to_ulong());
	}
}
