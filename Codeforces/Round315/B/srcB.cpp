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

bool compare(ii a, ii b) {
	return a.second < b.second;
}

int main(){
	int n, a;
	vii num;
	cin >> n;
	for (int i = 0;i  < n; i++) {
		cin >> a;
		num.push_back(ii(a, i));
	}
	int index[n+1];
	MEM(index, -1);
	vii tmp;
	for (int i = 0; i < num.size(); i++) {
		if (num[i].first <= n && index[num[i].first] == -1)
			index[num[i].first] = num[i].second;
		else {
			tmp.push_back(num[i]);
		}
	}
	int j = 1;
	for (int i = 0; i < tmp.size(); i++) {
		while (index[j] != -1)
			j++;
		tmp[i].first = j;
		index[j] = tmp[i].second;
	}
	vii ans;
	for (int i = 1; i < n+1; i++) {
		ans.push_back(ii(i, index[i]));
	}
	sort(ans.begin(), ans.end(), compare);
	for (int i = 0; i < n; i++)
		cout << ans[i].first << " ";
	cout << endl;
	return 0;
}
