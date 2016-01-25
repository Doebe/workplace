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
	int x, d, n;
	string s1, s2, C, M;
	while (cin >> x && x) {
		cin >> s1 >> s2 >> C;
		M = C;
		map<char, int> S, P;
		for (int i = 0; i < s1.size(); i++) {
			S[s1[i]] = i;
			P[s2[i]] = i;
		}
		n = C.size();
		d=((int)(pow(n, 1.5) + x)) % n;
//		printf("d = %d\n", d);
		int fromp = S[C[d]];
		char origin = s2[fromp];
		M[d] = origin;
//		cout << M[d] << endl;
		for (int j = d-1; (j+n)%n != d; j--) {
//			cout << j << endl;
			if (j == -1)
				j = n-1;
			int nums = S[M[(j+1)%n]];
			int prod = S[C[j]];
			int nump = nums ^ prod;
			M[j] = s2[nump];
		}
		cout << M << endl;
	}
	return 0;
}
