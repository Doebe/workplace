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
	int n, m;
	cin >> n >> m;
	string s;
	map<string, int> mm;
	for (int i = 0; i < n; i++){
		cin >> s;
//		cout << s << endl;
		for (int j = 0; j < s.size(); j++){
			char temp = s[j];
			if (temp != 'a'){
				s[j] = 'a';
				mm[s] = 0;
			}
			if (temp != 'b'){
				s[j] = 'b';
				mm[s] = 0;
			}
			if (temp != 'c'){
				s[j] = 'c';
				mm[s] = 0;
			}
			s[j] = temp;
		}
	}
//	for (map<string, int>::iterator it = mm.begin(); it != mm.end(); it++)
//		cout << it->first << endl;
	for (int i = 0; i < m; i++){
		cin >> s;
//		cout << s << endl;
		if (mm.count(s))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
