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
typedef pair<int, ii> iii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int n, v, d, p;
	vector<iii> c;
	cin >> n;
	int t[n];
	int a[n];
	MEM(t, 0);
//	MEM(a, 1);
	for (int i = 0; i < n; i++) {
		a[i] = 1;
//		cout << a[i] << " ";
	}
//	cout << endl;
	while (n--) {
		cin >> v >> d >> p;
		c.push_back(iii(v, ii(d, p)));
	}

	for (int i = 0; i < c.size(); i++) {
		if (!a[i])
			continue;
		if (c[i].second.second >= t[i]) {
			int cv = c[i].first;
			if (i == c.size()-1)
				continue;
			for (int j = i+1; j < c.size() && cv; j++) {
				if (!a[j])
					continue;
				t[j] += cv--;
			}
//			for (int j = i+1; j < c.size(); j++) {
//				if (!a[j])
//					continue;
//				if (c[j].second.second >= t[j])
//					continue;
//				a[j] = 0;
//				for (int k = j+1; k < c.size(); k++)
//					t[k] += c[j].second.first;
//			}
		} else {
			a[i] = 0;
			for (int k = i+1; k < c.size(); k++)
				t[k] += c[i].second.first;
		}
	}
	int cnt = 0;
	for (int i = 0; i < c.size(); i++)
		if (a[i])
			cnt++;
	cout << cnt << endl;
	for (int i = 0; i < c.size(); i++)
		if (a[i])
			cout << i+1 << " ";
	cout << endl;
	return 0;
}
