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

typedef struct point {
	double x, y;
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if (fabs(y - other.y) < eps)
			return x < other.x;
		return y < other.y;
	}
}P;

typedef struct edge {
	P p1, p2;
	double k;
	edge(P _p1, P _p2) {
		p1 = _p1 < _p2 ? _p1 : _p2;
		p2 = _p1 < _p2 ? _p2 : _p1;
		if (fabs(p2.x-p1.x) < eps)
			k = INF;
		else k = (p2.y-p1.y)/(p2.x-p1.x);
	}
	bool operator < (edge other) const {
		if (fabs(p1.y - other.p1.y) < eps)
			return p2.y > other.p2.y;
		return p1.y > other.p1.y;
	}
}E;

int main(){
	int n;
	double d, l, x, y;
	cin >> n >> d >> l;
	priority_queue <E> pq;
	vector<P> vp;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		vp.push_back(P(x, y));
	}

	for (int i = 0; i < n; i++) {
		pq.push(E(vp[i], vp[(i+1)%n]));
//		printf("(%lf, %lf), (%lf, %lf)\n", vp[i].x, vp[i].y, vp[(i+1)%n].x, vp[(i+1)%n].y);
	}

	pq.pop();
	double rem = l * 1000 / d;
//	printf("initial rem: %lf\n", rem);
	double h = 0;
	while (!pq.empty()) {
		if (pq.size() < 2)
			break;
		E e1 = pq.top(); pq.pop();
		E e2 = pq.top(); pq.pop();
//		printf("e1: (%lf, %lf), (%lf, %lf)\n", e1.p1.x, e1.p1.y, e1.p2.x, e1.p2.y);
//		printf("e2: (%lf, %lf), (%lf, %lf)\n", e2.p1.x, e2.p1.y, e2.p2.x, e2.p2.y);
		double ty = e1.p2.y;
		double tx;
		if (e2.k == INF)
			tx = e2.p1.x;
		else tx = e2.p1.x + (ty - e2.p1.y) / e2.k;
		P np(tx, ty);
//		printf("cut at: (%lf, %lf)\n", tx, ty);
		if (e2.p2.y > ty)
			pq.push(E(np, e2.p2));
		double dy = ty - e1.p1.y;
		double dx1 = fabs(e1.p1.x - e2.p1.x);
		double dx2 = fabs(e1.p2.x - tx);
		double area = (dx1 + dx2) * dy / 2;
//		printf("area: %lf, rem: %lf\n", area, rem);
		if (area < rem) {
			rem -= area;
			h += dy;
//			printf("current height: %lf, rem: %lf\n", h, rem);
			continue;
		}
		double a = 0;
		if (e1.p1.x < e2.p1.x) {
			if (e1.k != INF)
				a -= 1 / e1.k;
			if (e2.k != INF)
				a += 1 / e2.k;
		} else {
			if (e1.k != INF)
				a += 1 / e1.k;
			if (e2.k != INF)
				a -= 1 / e2.k;
		}
		if (a == 0)
			h += rem / dx1;
		else {
//			double a = 1 / sumk;
			double b = 2 * dx1;
			double c = -2 * rem;
//			printf("k: %lf, dx1: %lf\n", sumk, dx1);
			double dt = b*b-4*a*c;
			if (dt >= 0) {
				double dh1 = (-b + sqrt(dt))/2/a;
				double dh2 = (-b - sqrt(dt))/2/a;
//				printf("dh1: %lf, dh2: %lf\n", dh1, dh2);
				if (dh1 >= 0) {
					h += dh1;
//					printf("nx1: %lf, nx2: %lf, nx: %lf, area: %lf, dx1: %lf\n", dh1/e1.k, dh2/e2.k, dx1+dh1/e1.k+dh2/e2.k, (dh2/e2.k+dx1+dh1/e1.k+dh2/e2.k)*dh1/2, dx1);
				}
				else h += dh2;
			}
		}
//		printf("current height: %lf\n", h);
		break;
	}
	printf("%.2lf\n", h);
	return 0;
}

