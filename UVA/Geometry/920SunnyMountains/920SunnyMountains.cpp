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

struct point{
	double x, y;
	point(){
		x = y = 0.0;
	}
	point(double _x, double _y) : x(_x), y(_y){}
	bool operator < (point other) const{
		if (fabs(x - other.x) > eps)
			return x < other.x;
		return y < other.y;
	}
	bool operator == (point other) const{
		return fabs(x - other.x) < eps && fabs(y - other.y) < eps;
	}
};

int n, m, a, b;
point cur, prev;
double rst;

int main(){
	cin >> n;
	while (n--){
		cin >> m;
		vector<point> l;
		while (m--){
			cin >> a >> b;
			l.push_back(point(a, b));
		}
		sort(l.begin(), l.end());
		prev = l[l.size()-1];
		rst = 0;
		for (int i = l.size() - 2; i >= 0; i--){
			cur = l[i];
			if (cur.y <= prev.y)
				continue;
			double d = cur.y - prev.y;
			double s = sqrt((cur.y - l[i+1].y)*(cur.y - l[i+1].y)
						+(cur.x - l[i+1].x)*(cur.x - l[i+1].x))/(cur.y - l[i+1].y)*d;
			rst += s;
			prev = cur;
		}
		printf("%.2lf\n", rst);
	}
}
