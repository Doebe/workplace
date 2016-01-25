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
	while (1){
		int n;
		cin >> n;
		if (n<0)
			break;
		cout << n << " coconuts, ";
		if (n == 0 || n == 1)
			cout << "no solution" << endl;
		else{
			int i = 2;
			vi fac;
			while (true){
				if (pow(i, i) <= n)
					fac.push_back(i++);
				else {
					fac.push_back(i);
					break;
				}
			}
			bool found = false;
			int ans = 0;
			for (int i = fac.size() - 1; i >= 0; i--){
				int m = n;
				for (int j = 0; j < fac[i]; j++){
					if ((m - 1) % fac[i] != 0)
						break;
					m = m - 1 - m / fac[i];
					if (j == fac[i] - 1 && m % fac[i] == 0)
						found = true;
				}
				if (found){
					ans = fac[i];
					break;
				}
			}
			if (ans == 0)
				cout << "no solution" << endl;
			else cout << ans << " people and 1 monkey" << endl;
		}
	}
	return 0;
}
