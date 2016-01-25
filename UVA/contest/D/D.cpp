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

vi mini;
int n, a, minimum;

int main(){
	cin >> n;
	while (n--) {
		scanf("%d\n", &a);
		minimum = INF;
		for (int i = 1; i <= a; i++){
			string line;
			stringstream ss;
			getline(cin, line);
			ss.str(line);
			int nextInt, cnt = 0;
			while (ss >> nextInt)
				cnt++;
			if (cnt < minimum){
				minimum = cnt;
				mini.clear();
				mini.push_back(i);
			}else if (cnt == minimum)
				mini.push_back(i);
		}
		for (int i = 0; i < mini.size() - 1; i++)
			cout << mini[i] << " ";
		cout << mini[mini.size() - 1] << endl;
	}
	return 0;
}
