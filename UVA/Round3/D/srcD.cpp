// 11483

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
	int n, c = 0;;
	string ns;
	while (cin >> n && n) {
		getline(cin, ns);
		c++;
		cout << "Case " << c << ":" << endl;
		vector<string> s;
		while (n--) {
			getline(cin, ns);
//			cout << ns << endl;
			s.push_back(ns);
		}
		cout << "#include<string.h>" << endl;
		cout << "#include<stdio.h>" << endl;
		cout << "int main()" << endl;
		cout << "{" << endl;
		for (int i = 0; i < s.size(); i++) {
			cout << "printf(\"";
			for (int j = 0; j < s[i].size(); j++) {
				if (s[i][j] == '\\' || s[i][j] == '\"')
					cout << '\\';
				cout << s[i][j];
			}
			cout << "\\n\");" << endl;
		}
		cout << "printf(\"\\n\");" << endl;
		cout << "return 0;" << endl;
		cout << "}" << endl;
	}
	return 0;
}
