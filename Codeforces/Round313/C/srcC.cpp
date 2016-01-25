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
	vi A;
	int a, total = 0;
	ll sum = 0;
	for (int i = 0; i < 6; i++) {
		cin >> a;
		A.push_back(a);
		total += a;
	}
	ll corner = 0;
	int z = 0;
	while (1) {
		for (int i = 0; i < 6; i++) {
			if (A[i] <= 0)
				continue;
			sum += (2 * A[i] - 1);
			A[i]--;
//			cout << "i = " << i << " : " << A[i] << endl;
		}
//		cout << "sum = " <<  sum <<  endl;
		for (int i = 0; i < 6; i++) {
			if (A[i] == 0) {
				if (A[(i+5)%6] != 0 && A[(i+7)%6] != 0) {
//					cout << --A[(i+5)%6] << endl;
//					cout << --A[(i+7)%6] << endl;
					--A[(i+5)%6];
					--A[(i+7)%6];
					if (A[(i+5)%6] != 0 && A[(i+7)%6] != 0) {
						A[i]++;
						corner++;
					}
				}
			}
//			cout << "new A[i]: " << A[i] << endl;
		}
		int flag = 1;
		for (int i = 0;i  < 6; i++)
			if (A[i] != 0)
				flag = 0;
		if (flag)
			break;
	}
	cout << sum + corner << endl;
	return 0;
}
