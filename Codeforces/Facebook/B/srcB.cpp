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
//	for (int i = 1; i <= 100000; i++)
//		cout << i << endl;
//	return 0;
	int t, n;
	cin >> t;
	for (int c = 1; c <= t; c++) {
		cin >> n;
		map<string, int> dic;
		string line;
		getline(cin, line);
		int total = 0;
		while (n--) {
			getline(cin, line);
//			cout << line << endl;
			if (dic.count(line)) {
				total += line.size();
				continue;
			}
			int found = 0;
			for (int i = 1; i <= line.size(); i++) {
				string sub = line.substr(0, i);
//				cout << sub << endl;
				if (!found && !dic.count(sub)) {
					found = 1;
					total += i;
//					cout << sub << " " << total << endl;
				}
				dic[sub] = 1;
			}
		}
		printf("Case #%d: %d\n", c, total);
	}
	return 0;
}
