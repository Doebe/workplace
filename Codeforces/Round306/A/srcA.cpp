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
	string line;
	getline(cin, line);
	int n = line.size();
	vi ab, ba;
	bool yes = false;
	for (int i = 0; i < n-1; i++){
		if (line[i] == 'A' && line[i+1] == 'B')
			ab.push_back(i);
		if (line[i] == 'B' && line[i+1] == 'A')
			ba.push_back(i);
	}
	for (int i = 0; i < ab.size(); i++){
		int curA = ab[i];
		for (int j = 0; j < ba.size(); j++)
			if (abs(curA - ba[j]) >= 2){
				yes = true;
				break;
			}
		if (yes)
			break;
	}
	if (yes)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
