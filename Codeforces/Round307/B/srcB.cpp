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
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

int main() {
	string a, b, c;
	cin >> a >> b >> c;
	vi dic1(26, 0);
	vi dic2(26, 0);
	int total1 = 0;
	int total2 = 0;
	for (int i = 0; i < a.size(); i++) {
		dic1[a[i] - 'a']++;
		dic2[a[i] - 'a']++;
	}


	vi dicb(26, 0);
	for (int i = 0; i < b.size(); i++)
		dicb[b[i] - 'a']++;
	vi dicc(26, 0);
	for (int i = 0; i < c.size(); i++)
		dicc[c[i] - 'a']++;



	double r1 = INF;
	for (int i = 0; i < 26; i++)
//		cout << dic1[b[i]-'a'] << " " << dicb[b[i]-'a']<<endl;
		if (dicb[i] > 0)
			r1 = min(r1, (double)dic1[i] / dicb[i]);
	total1 += floor(r1);
	for (int i = 0; i < 26; ++i) {
//		cout << b[i] << " " << dic1[b[i]-'a'] << endl;
		dic1[i] -= total1 * dicb[i];
//		cout << b[i] << " " << dic1[b[i]-'a'] << endl;
	}
	r1 = INF;
	for (int i = 0; i < 26; i++){
		if (dicc[i] > 0)
			r1 = min(r1, (double)dic1[i] / dicc[i]);
	}
	r1 = floor(r1);
	for (int i = 0; i < 26; ++i) {
		dic1[i] -= r1 * dicc[i];
	}

	double r2 = INF;
	for (int i = 0; i < 26; i++)
		if (dicc[i]>0)
			r2 = min(r2, (double)dic2[i] / dicc[i]);
	total2 += floor(r2);
	for (int i = 0; i < 26; ++i) {
		dic2[i] -= total2 * dicc[i];
	}
	r2 = INF;
	for (int i = 0; i < 26; i++){
		if (dicb[i] > 0)
			r2 = min(r2, (double)dic2[i] / dicb[i]);
	}
	r2 = floor(r2);
	for (int i = 0; i < 26; ++i) {
		dic2[i] -= r2 * dicb[i];
	}

	string s = "";
	if (r1 + total1 > r2 + total2){
		for (int i = 0; i < total1; i++)
			s += b;
		for (int i = 0; i < r1; i++)
			s += c;
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < dic1[i]; j++)
				s += ('a' + i);
	}else{
		for (int i = 0; i < total2; i++)
			s += c;
		for (int i = 0; i < r2; i++)
			s += b;
		for (int i = 0; i < 26; i++)
			for (int j = 0; j < dic2[i]; j++)
				s += ('a' + i);
	}
	cout << s << endl;
	return 0;
}
