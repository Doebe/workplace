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

string line;
int n;

int find(){
	for (int i = 0; i < n; i++){
		int a = line[i]-'0';
		if (a % 8 == 0)
			return a;
		for (int j = i+1; j < n; j++){
			int b = line[j]-'0';
			if (b % 8 == 0)
				return b;
			int num = a * 10 + b;
			if (num % 8 == 0)
				return num;
			for (int k = j+1; k < n; k++){
				int c = line[k]-'0';
				int num = a * 100 + b * 10 + c;
				if (num % 8 == 0)
					return num;
				num = a * 10 + c;
				if (num % 8 == 0)
					return num;
				num = b * 10 + c;
				if (num % 8 == 0)
					return num;
				num = c;
				if (num % 8 == 0)
					return num;
			}
		}
	}
	return -1;
}


int main(){
	getline(cin, line);
	n = line.size();
	int ans = find();
	if (ans == -1)
		cout << "NO" << endl;
	else cout << "YES\n" << ans << endl;
	return 0;
}
