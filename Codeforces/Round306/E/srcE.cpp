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

int n;
string line;

bool possible(int l, int b){
	int cur = line[l]-'0';
	if (l == 0){
		if (cur == b)
			return true;
		return false;
	}
	if (!b){
		if (cur)
			return false;
		return possible(l-2, 1);
	}
	if (cur)
		return true;
	for (int i = l-2; i >= 0; i-=2){
		if (line[i]-'0' == 0){
			line[i+1] = '(';
			if (i == 0){
				line.insert(0, 1, ' ');
				i++, l++;
			}
			line[i-1] = '(';
			line[l+1] = ')';
			line.insert(l+1, 1, ')');
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d\n", &n);
	getline(cin, line);
	int len = line.size();
	if (!possible(len-1, 0))
		cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		len = line.size();
		for (int i = 0; i < len; i++){
			if (line[i] == ' '){
				line[i] = '-';
				line.insert(i+1, 1, '>');
				i++, len++;
			}
			else if (line[i] == '(' && i != 0){
				line.insert(i, "->");
				i+=2, len+=2;
			}
			else if (line[i] >= '0' && line[i] <= '9'){
				if (i != 0 && line[i-1] == ')'){
					line.insert(i, "->");
					i+=2, len+=2;
				}
			}
		}
		cout << line << endl;
	}
	return 0;
}
