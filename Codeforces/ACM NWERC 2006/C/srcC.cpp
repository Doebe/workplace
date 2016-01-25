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
	int t, n;
	string line;
	scanf("%d", &t);
	while (t--) {
		scanf("%d\n", &n);
		getline(cin, line);
		int cnt = 0;
		if (line[0] == '*' && line[1] == '.')
			line[1] = '#';
		if (line[n-1] == '*' && line[n-2] == '.')
			line[n-2] = '#';
		for (int i = 1; i < line.size()-1; i++) {
			if (line[i] == '*') {
				if (line[i-1] == '.')
					line[i-1] = '#';
				if (line[i+1] == '.')
					line[i+1] = '#';
			}
		}
		int c = 0;
		for (int i = 0; i < line.size();) {
			if (line[i] == '.'){
				c = 0;
				for (int j = i; j < line.size(); j++) {
					if (line[j] == '.'){
						c++;
						if (j == n-1) {
							i = j+1;
							break;
						}
					}
					else {
						i = j + 1;
						break;
					}
				}
				cnt += ceil((double)c/3);
			} else i++;
		}

		printf("%d\n", cnt);
	}
	return 0;
}
