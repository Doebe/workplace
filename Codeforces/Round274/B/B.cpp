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
	int t, cs = 0;
	scanf("%d\n", &t);
	string line;
	while (t--){
		double y = INF, i = INF, pr = INF;
		bool x = false, o = false, z = false;
		getline(cin, line);
		stringstream ss;
		ss.str(line);
		char c, p, u;
		double v;
		while (ss >> c){
			if (c == 'I'){
				ss >> c;
				if (c != '=')
					continue;
				ss >> v;
//				cout << v << endl;
				ss >> u;
				if (u != 'A'){
					if (u == 'm'){
						v = v / 1000;
					}else if (u == 'k'){
						v = v * 1000;
					}else v = v * 1000000;
					ss >> u;
				}
				i = v;
//				cout << "i: " << i << endl;
				x = true;
			}else if (c == 'P'){
				ss >> c;
				if (c != '=')
					continue;
				ss >> v;
				ss >> u;
				if (u != 'W'){
					if (u == 'm'){
						v = v / 1000;
					}else if (u == 'k'){
						v = v * 1000;
					}else v = v * 1000000;
					ss >> u;
				}
				pr = v;
//				cout << "pr: " << pr << endl;
				o = true;
			} else if (c == 'U'){
				ss >> c;
				if (c != '=')
					continue;
				ss >> v;
				ss >> u;
				if (u != 'V'){
					if (u == 'm'){
						v = v / 1000;
					}else if (u == 'k'){
						v = v * 1000;
					}else v = v * 1000000;
					ss >> u;
				}
				y = v;
//				cout << "y: " << y << endl;
				z = true;
			}
		}
		printf("Problem #%d\n", ++cs);
		if (x && z)
			printf("P=%.2lfW\n\n", y * i);
		else if (o && z)
			printf("I=%.2lfA\n\n", pr / y);
		else printf("U=%.2lfV\n\n", pr / i);
	}
}
