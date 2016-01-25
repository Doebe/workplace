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
	int n;
	scanf("%d\n", &n);
	string line;
	while (n--){
		getline(cin, line);
		int sum = 0;
		int inc = 0, dec = 0;
		for (int i = 0; i < line.size(); i++){
			int cur = line[i]-'0';
			sum += cur;
			if (i == 0 && line.size() > 1)
				dec += cur-1;
			else
				dec += cur-0;
			inc += 9-cur;
		}
		int mod = sum % 9;
		if (mod == 0){
			printf("%d\n", 0);
			continue;
		}
		if (mod < 5){
			if (mod <= dec)
				printf("%d\n", mod);
			else printf("%d\n", 9-mod);
		}else{
			if (9-mod <= inc)
				printf("%d\n", 9-mod);
			else printf("%d\n", mod);
		}
	}
	return 0;
}
