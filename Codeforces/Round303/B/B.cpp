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
	string line1;
	string line2;
	getline(cin, line1);
	getline(cin, line2);
	int total = 0;
	char dig1, dig2;
	for (int i = 0; i < line1.size(); i++){
		dig1 = line1[i];
		dig2 = line2[i];
		if (dig1 != dig2)
			total++;
	}
	if (total % 2 == 1)
		cout << "impossible" << endl;
	else{
		int semitotal = total / 2;
		for (int i = 0; i < line1.size(); i++){
			if (line1[i] != line2[i]){
				line1[i] = line2[i];
				semitotal--;
				if (semitotal == 0)
					break;
			}
		}
		cout << line1 << endl;
	}
	return 0;
}
