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
typedef pair<double, double> dd;
typedef pair<dd, dd> dddd;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int c, n;
	double r, x, y, d, s;
	scanf("%d", &c);
	while (c--){
		scanf("%d %lf", &n, &r);
		vector<dddd> boats;
		int mini = INF;
		while (n--){
			scanf("%lf %lf %lf %lf", &x, &y, &d, &s);
			d = d/180*PI;
			for (int i = 0; i < boats.size(); i++){
				dddd cur = boats[i];
				double x1 = cur.first.first;
				double y1 = cur.first.second;
				double d1 = cur.second.first;
				double s1 = cur.second.second;
				double distance = hypot((x1-x), (y1-y));
				if (distance < r || fabs(distance-r) < eps){
					mini = 0;
					break;
				}
//				cout << x1 << " " << y1 << " " << d1 << " " << s1 << endl;
				double s1y = s1 * cos(d1);
				double s1x = s1 * sin(d1);
				double sy = s * cos(d);
				double sx = s * sin(d);
//				cout << d << " " << s << " " << sx << endl;
//				cout << sx << " " << sy << " " << s1x << " " << s1y << endl;
				double newsy = sy - s1y;
				double newsx = sx - s1x;
//				cout << newsx << " " << newsy << endl;
				if (fabs(newsx) < eps){
					if (fabs(newsy) < eps || newsy * (y1-y) < 0 || abs(x1-x) > r)
						continue;
					double dist = fabs(y1-y) - sqrt(r*r - (x1-x)*(x1-x));
					double speed = fabs(newsy);
					int time = round(dist/speed);
					mini = min(mini, time);
					continue;
				}
				double k = newsy / newsx;
				double b = y - k * x;
//				cout << k << " " << b << endl;
				double delta = (2*x1-2*b*k+2*y1*k)*(2*x1-2*b*k+2*y1*k)-4*(k*k+1)*(x1*x1+b*b-2*y1*b+y1*y1-r*r);
//				cout << x1 << " " << b << " " << k << " " << y1 << endl;
//				cout << 2*x1-2*b*k + 2*y1*k << " " << delta << endl;
				if (delta < 0)
					continue;
				double ans1x = (2*x1-2*b*k+2*y1*k-sqrt(delta))/(2*(k*k+1));
				double ans2x = (2*x1-2*b*k+2*y1*k+sqrt(delta))/(2*(k*k+1));
				if (newsx * (ans1x - x) < 0 && newsx * (ans2x - x) < 0)
					continue;
//				cout << 2*x1-2*b*k+2*y1*k << endl;
//				cout << ans1x << " " << ans2x << " " << 5*sqrt(2) << endl;
				double intersectx;
				double intersecty;
				double difx1 = fabs(ans1x-x), difx2 = fabs(ans2x-x);
				if (difx1 < difx2)
					intersectx = ans1x;
				else if (difx1 > difx2)
					intersectx = ans2x;
				else {
					double ans1y = ans1x * k + b;
					double ans2y = ans2x * k + b;
					double dify1 = fabs(ans1y-y), dify2 = fabs(ans2y-y);
					if (dify1 < dify2)
						intersectx = ans1x;
					else intersectx = ans2x;
				}
				intersecty = intersectx * k + b;
//				cout << intersectx << " " << intersecty << " " << 2.5*sqrt(2) << endl;
				double dist = hypot((intersecty - y), (intersectx - x));
				double speed = hypot(newsy, newsx);
				int time = round(dist/speed);
				mini = min(mini, time);
			}
			boats.push_back(dddd(dd(x, y), dd(d, s)));
		}
		if (mini == INF)
			printf("No collision.\n");
		else printf("%d\n", mini);
	}
	return 0;
}
