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
	int k;
	while (scanf("%d\n", &k) == 1){
		string line;
		getline(cin, line);
		stringstream ss;
		ss.str(line);
		vi p, q;
		string s;
		while (ss >> s){
//			cout << s << endl;
			int a = atoi(s.c_str());
//			cout << a << endl;
			p.push_back(a);
		}
		q.push_back(p[0]);
		for (int i = 1; i < p.size(); i++){
			q.push_back(p[i] + k * q[i-1]);
		}
		printf("q(x): ");
		for (int i = 0; i < q.size()-2; i++)
			printf("%d ", q[i]);
		printf("%d\n", q[q.size()-2]);
		printf("r = %d\n\n", q[q.size()-1]);
	}
}
