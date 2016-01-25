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
typedef vector<double> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int t, m, x, y, h;
	cin >> t;
	while(t--) {
		vi houses(101, 0);
		cin >> m >> x >> y;
		int c = x * y;
		while (m--) {
			cin >> h;
			int low = max(h-c, 1);
			int high = min(100, h+c);
			for (int i = low; i <= high; i++)
				houses[i] = 1;
		}
		int cnt = 0;
		for (int i = 1; i <= 100; i++)
			if (houses[i] == 0)
				cnt++;
		cout << cnt << endl;
	}
	return 0;
}

