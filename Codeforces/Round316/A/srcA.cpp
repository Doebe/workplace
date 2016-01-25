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
	int n, m, v;
	cin >> n >> m;
	vi cities(n, 0);
	vii city;
//	for (int i = 0; i < m; i++)
//		cities.push_back(ii(0, i));
	int mx = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v;
			city.push_back(ii(v, j));
		}
		sort(city.begin(), city.end());
		int winner;
		for (int j = n-1; j>=0; j--) {
			if (j == n-1) {
				winner = city[j].second;
				continue;
			}
			if (city[j].first < city[j+1].first)
				break;
			winner = min(winner, city[j].second);
		}
//		cout << winner << endl;
		cities[winner]++;
		mx = max(mx, cities[winner]);
		city.clear();
	}
	for (int i = 0; i < n; i++)
//		cout << cities[i] << " ";
//	cout << endl;
		if (cities[i] == mx){
			cout << i+1 << endl;
			break;
		}
	return 0;
}
