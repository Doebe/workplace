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

struct pointI{
	int x, y;
	pointI() {x = y = 0;}
	pointI(int _x, int _y) : x(_x), y(_y) {}
};

struct point{
	double x, y;
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if (fabs(x - other.x) > eps)
			return x < other.x;
		return y < other.y;
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < eps && (fabs(y - other.y) < eps));
	}

};

double dist(point p1, point p2){
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

struct vec{
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b){
	return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s){
	return vec(v.x * s, v.y * s);
}

point translate(point p, vec v){
	return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b){
	return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v){
	return v.x * v.x + v.y * v.y;
}

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c){
	// formula : c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u));
	return dist(p, c);
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point&c){
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	if (u < 0.0) {
		c = point(a.x, a.y);
		return dist(p, a);
	}
	if (u > 1.0) {
		c = point(b.x, b.y);
		return dist(p, b);
	}
	return distToLine(p, a, b, c);
}

double angle(point a, point o, point b){
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b){
	return a.x * b.y - a.y * b.x;
}

// note: to accept collinear points, we have to change the '> 0'
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r){
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r){
	return fabs(cross(toVec(p, q), toVec(p, r))) < eps;
}

/******************POLYGON***********************/

double perimeter(const vector<point> &P){
	double result = 0.0;
	for (int i = 0; i < (int)P.size()-1; i++)
		result += dist(P[i], P[i+1]);
	return result;
}

double area(const vector<point> &P){
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size()-1; i++){
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}

bool isConvex(const vector<point> &P){	// returns true if all three consecutive vertices of P form the same turns
	int sz = (int)P.size();
	if (sz <= 3) return false;	// a point/sz = 2 or a line/sz = 3 is not convex
	bool isLeft = ccw(P[0], P[1], P[2]);	// remember one result
	for (int i = 1; i < sz-1; i++)	// then compare with the others
		if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
			return false;	//different sign -> this polygon is concave
	return true;	// this polygong is convex
}

bool inPolygon(point pt, const vector<point> &P){
	if ((int)P.size() == 0) return false;
	double sum = 0;
	for (int i = 0; i < (int)P.size()-1; i++){
		if (ccw(pt, P[i], P[i+1]))
			sum += angle(P[i], pt, P[i+1]);
		else sum -= angle(P[i], pt, P[i+1]);
	}
	return fabs(fabs(sum) - 2*PI) < eps;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B){
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u+v), (p.y * v + q.y * u) / (u+v));
}

// cuts polygon Q along the line formed by point a -> point b
// notes: the last point must be the same as the first point
vector<point> cutPolygon(point a, point b, const vector<point> &Q){
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++){
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size()-1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
		if (left1 > -eps) P.push_back(Q[i]); // Q[i] is on the left of ab
		if (left1 * left2 < -eps)	// edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front());	// make P's first point = P's last point
	return P;
}

point pivot(0, 0);
bool angleCmp(point a, point b){	// angle-sorting function
	if (collinear(pivot, a, b))	// special case
		return dist(pivot, a) < dist(pivot, b);	// check which one is closer
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;	// compare two angles
}

vector<point> CH(vector<point> P){	// the content of P may be reshuffled
	int i, j, n = (int)P.size();
	if (n <= 3){
		if (!(P[0] == P[n-1])) P.push_back(P[0]);	// safeguard from corner case
		return P;	// special case, the CH is P itself
	}

	// first, find PO = point with lowest Y and if tie: right most X
	int P0 = 0;
	for (i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	point temp = P[0]; P[0] = P[P0]; P[P0] = temp;	// swap P[P0] with P[0]

	// second, sort points by angle w.r.t. pivot P0
	pivot = P[0];	// use this global variable as reference
//	cout << "pivot: " << pivot.x << " " << pivot.y << endl;
	sort(++P.begin(), P.end(), angleCmp);	// we do not sort P[0]
//	for (int i = 0; i < P.size(); i++)
//		cout << "sorted: " << P[i].x << " " << P[i].y << endl;

	// third, the ccw tests
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);	// initial S
	i = 2;	// then, we check the rest
	while (i < n){	// note: N must be >= 3 for this method to work
		j = (int)S.size() - 1;
		if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);	// left turn, accept
		else S.pop_back();	// or pop the top of S until we have a left turn
	}
	return S;
}

int main(){
	int v, x, y, cs = 0;
	while (scanf("%d", &v) && v){
		vector<point> p;
		while (v--){
			scanf("%d %d", &x, &y);
			p.push_back(point(x, y));
		}
		p.push_back(p[0]);
		vector<point> chp = CH(p);
		double mini = INF;
		for (int i = 0; i < chp.size()-1; i++){
			double maxi = 0.0;
			for (int j = 0; j < chp.size()-1; j++){
				point c;
//				printf("%.0lf,%.0lf to %.0lf,%.0lf and %.0lf,%.0lf\n", chp[j].x, chp[j].y, chp[i].x, chp[i].y, chp[i+1].x, chp[i+1].y);
//				cout << maxi << " " << distToLine(chp[j], chp[i], chp[i+1], c) << endl;
				maxi = max(maxi, distToLine(chp[j], chp[i], chp[i+1], c));
			}
			mini = min(mini, maxi);
		}
		double ans = ceil(mini * 100) / 100.0;
		printf("Case %d: %.2lf\n", ++cs, ans);
	}
}
