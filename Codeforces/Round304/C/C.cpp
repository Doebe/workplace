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
	int n, k1, k2, cur;
	cin >> n >> k1;
	queue<int> q1;
	for (int i = 0; i < k1; i++){
		cin >> cur;
		q1.push(cur);
	}
	cin >> k2;
	queue<int> q2;
	for (int i = 0; i < k2; i++){
		cin >> cur;
		q2.push(cur);
	}
	int cnt = 0;
	while (k1 != n && k2 != n && cnt < 10000){
		int f1, f2;
		f1 = q1.front(); q1.pop();
		k1--;
		f2 = q2.front(); q2.pop();
		k2--;
		if (f1 < f2){
			q2.push(f1);
			k2++;
			q2.push(f2);
			k2++;
		}else {
			q1.push(f2);
			k1++;
			q1.push(f1);
			k1++;
		}
		cnt++;
	}
	if (cnt == 10000)
		cout << -1 << endl;
	else {
		cout << cnt << " " << (k1 > k2 ? 1 : 2) << endl;
	}
}
