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
	int n, m, a;
	cin >> n >> m;
	int arr[m];
	MEM(arr, 0);
	for (int i = 0; i < n; i++) {
		cin >> a;
		a %= m;
		arr[a] = 1;
	}
	for (int i = 0; i < m; i++)
		cout << arr[i] << " ";
	cout << endl;
	vector<vi> sum(m, vi());
	if (arr[0])
		sum[0].push_back(0);
	int found = 0;
	for (int i = 1; i < m; i++) {
		if (arr[i]) {
			sum[i].push_back(i);
			for (int j = 0; j < sum[i-1].size(); j++) {
				int tmp = (i+sum[i-1][j])%m;
				if (tmp == 0) {
					found = 1;
					break;
				}
				sum[i].push_back(tmp);
			}
		} else sum[i] = sum[i-1];
		if (found)
			break;
	}
	for (int i = 0; i < m ;i++) {
		for (int j = 0; j < sum[i].size(); j++)
			cout << sum[i][j] << " ";
		cout << endl;
	}
	if (found)
		cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
