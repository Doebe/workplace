//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAX_INT = std::numeric_limits<int>::max();
//const int MIN_INT = std::numeric_limits<int>::min();
//const int INF = 1000000000;
//const int NEG_INF = -1000000000;
//
//#define max(a,b)(a>b?a:b)
//#define min(a,b)(a<b?a:b)
//#define MEM(arr,val)memset(arr,val, sizeof arr)
//#define PI acos(0)*2.0
//#define eps 1.0e-9
//#define are_equal(a,b)fabs(a-b)<eps
//#define LS(b)(b& (-b)) // Least significant bit
//#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians
//
//typedef long long ll;
//typedef pair<int, int> ii;
//typedef pair<int, char> ic;
//typedef pair<long, char> lc;
//typedef vector<int> vi;
//typedef vector<ii> vii;
//
//int gcd(int a, int b) {
//	return b == 0 ? a : gcd(b, a % b);
//}
//int lcm(int a, int b) {
//	return a * (b / gcd(a, b));
//}
//
//struct point {
//	int x, y;
//	point() {
//		x = y = 0;
//	}
//	point(int x1, int y1) :
//			x(x1), y(y1) {
//	}
//	point(const point &p) :
//			x(p.x), y(p.y) {
//	}
//	point operator +(const point &p) const {
//		return point(x + p.x, y + p.y);
//	}
//	point operator -(const point &p) const {
//		return point(x - p.x, y - p.y);
//	}
//	point operator *(double c) const {
//		return point(x * c, y * c);
//	}
//	point operator /(double c) const {
//		return point(x / c, y / c);
//	}
//};
//
//struct vec {
//	double x, y;
//	vec(double x1, double y1) :
//			x(x1), y(y1) {
//	}
//};
//
//vec toVec(point a, point b) {
//	return vec(b.x - a.x, b.y - a.y);
//}
//
//int cross(vec a, vec b) {
//	return a.x * b.y - a.y * b.x;
//}
//
//int ccw(point p, point q, point r) {
//	int value = cross(toVec(p, q), toVec(p, r));
//	if (value == 0)
//		return 0;
//	return value > 0 ? 1 : 2;
//}
//
//bool onSegment(point p, point q, point r) {
//	if (r.x <= max(p.x, q.x) && r.x >= min(p.x, q.x) && r.y <= max(p.y, q.y)
//			&& r.y >= min(p.y, q.y))
//		return true;
//	return false;
//}
//
//double dot(vec a, vec b) {
//	return (a.x * b.x + a.y * b.y);
//}
//
//double dot(point p, point q) {
//	return p.x * p.x + p.y * p.y;
//}
//double dist2(point p, point q) {
//	return dot(p - q, p - q);
//}
//double cross(point p, point q) {
//	return p.x * q.y - p.y * q.x;
//}
//// determine if lines from a to b and c to d are parallel or collinear
//bool LinesParallel(point a, point b, point c, point d) {
//	return fabs(cross(b - a, c - d)) < eps;
//}
//bool LinesCollinear(point a, point b, point c, point d) {
//	return LinesParallel(a, b, c, d) && fabs(cross(a - b, a - c)) < eps
//			&& fabs(cross(c - d, c - a)) < eps;
//}
//// determine if line segment from a to b intersects with
//// line segment from c to d
//bool SegmentsIntersect(point a, point b, point c, point d) {
//	if (LinesCollinear(a, b, c, d)) {
//		if (dist2(a, c) < eps || dist2(a, d) < eps || dist2(b, c) < eps
//				|| dist2(b, d) < eps)
//			return true;
//		if (dot(c - a, c - b) > 0 && dot(d - a, d - b) > 0
//				&& dot(c - b, d - b) > 0)
//			return false;
//		return true;
//	}
//	if (cross(d - a, b - a) * cross(c - a, b - a) > 0)
//		return false;
//	if (cross(a - c, d - c) * cross(b - c, d - c) > 0)
//		return false;
//	return true;
//}
//
//double norm_sq(vec v) {
//	return v.x * v.x + v.y * v.y;
//}
//
//double angle(point a, point o, point b) {
//	vec oa = toVec(o, a), ob = toVec(o, b);
//	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
//}
//
//bool inPolygon(point pt, const vector<point> &p) {
//	if ((int) p.size() == 0)
//		return false;
//	double sum = 0;
//	for (int i = 0; i < (int) p.size() - 1; i++) {
//		if (ccw(pt, p[i], p[i + 1]) == 1)
//			sum += angle(p[i], pt, p[i + 1]);
//		else
//			sum -= angle(p[i], pt, p[i + 1]);
//	}
//	if (ccw(pt, p[p.size() - 1], p[0]) == 1)
//		sum += angle(p[p.size() - 1], pt, p[0]);
//	else
//		sum -= angle(p[p.size() - 1], pt, p[0]);
//	return fabs(fabs(sum) - 2 * PI) < eps;
//}
//
//bool intersect(const vector<point> &va, const vector<point> &vb) {
//	for (int i = 0; i < va.size(); i++) {
//		for (int j = 0; j < vb.size(); j++) {
//			point a, b, c, d;
//			a = va[i];
//			if (i == va.size() - 1)
//				b = va[0];
//			else
//				b = va[i + 1];
//			c = vb[j];
//			if (j == vb.size() - 1)
//				d = vb[0];
//			else
//				d = vb[j + 1];
//			if (SegmentsIntersect(a, b, c, d))
//				return true;
////			cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y<<" "<<d.x<<" "<<d.y<<endl;
////
////			int o1 = ccw(a, b, c);
////			int o2 = ccw(a, b, d);
////			int o3 = ccw(c, d, a);
////			int o4 = ccw(c, d, b);
////
////			// General case
////			if (o1 != o2 && o3 != o4)
////				return true;
////			// Special Cases
////			// a, b and c are colinear and c lies on segment ab
////			if (o1 == 0 && onSegment(a, b, c))
////				return true;
////
////			// a, b and c are colinear and d lies on segment ab
////			if (o2 == 0 && onSegment(a, b, d))
////				return true;
////
////			// c, d and a are colinear and a lies on segment cd
////			if (o3 == 0 && onSegment(c, d, a))
////				return true;
////
////			// c, d and b are colinear and b lies on segment cd
////			if (o4 == 0 && onSegment(c, d, b))
////				return true;
//		}
//	}
//	return false;
//}

#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

#define max(a,b)(a>b?a:b)
#define min(a,b)(a<b?a:b)
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI (acos(0)*2.0)
#define eps 1.0e-9
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b&(-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

//----------------------------------------------------------------------//
struct point{
    double x,y;
    point(){x = y = 0.0;}
    point(double _x, double _y) : x(_x),y(_y){ }
    bool operator < (point other) const {
        if(!are_equal(x,other.x))
            return x < other.x;
        return y < other.y;
    }
    bool operator == (point other) const {
        return are_equal(x,other.x) && are_equal(y,other.y);
    }
};

struct vec{
    double x,y;
    vec(){x = y = 0.0;}
    vec(double _x, double _y) : x(_x),y(_y){}
    vec(point p1, point p2) : x(p2.x-p1.x),y(p2.y-p1.y){}
    vec scale(double s){
        return vec(this->x * s,this->y * s);
    }
};
/**
 * a*x + b*y + c = 0
 * a = -slope
 * c = -(y-intersect)
 */
struct line{
    double a,b,c;
    line(){a=b=c=0.0;}
    line(double _a,double _b,double _c): a(_a),b(_b),c(_c){}
    line(point p1, point p2){
        if(are_equal(p1.x,p2.x)){
            a = 1.0;
            b = 0.0;
            c = -p1.x;
        }else{
            a = -(double)(p1.y - p2.y)/(p1.x - p2.x);// slope
            b = 1.0;
            c = -(double)(a*p1.x)-p1.y;
        }
    }
};
double cross(vec a, vec b){return a.x*b.y - a.y*b.x;}
double dot(vec a, vec b){return a.x * b.x + a.y * b.y;}
double norm_sq(vec a){return a.x * a.x + a.y * a.y;}
double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y- p2.y);
}
vec toVec(point a, point b){
    return vec(b.x - a.x, b.y - a.y);
}
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r){
    return fabs(cross(vec(p,q),vec(p,r)) )<  eps;
}

bool ccw(point p, point q, point r){
    return ( collinear(p,q,r)) || cross(vec(p,q),vec(p,r)) > 0;
}

// oa*ob = |oa|*|ob|*cos(theta), theta = arccos(oa*ob / (|oa|*|ob|) )
double angle(point a, point o, point b){
    vec oa(o,a), ob(o,b);
    return acos(dot(oa,ob)/ sqrt(norm_sq(oa)*norm_sq(ob)));
}

bool inPolygon(point pt, const vector<point> &P){
    if((int)P.size() == 0)return false;
    double sum = 0.0;
    for (int i = 0; i < (int)P.size()-1; ++i) {
        if(ccw(pt,P[i],P[i+1]))
            sum += angle(P[i],pt,P[i+1]);
        else
            sum -= angle(P[i],pt,P[i+1]);

    }
    return fabs(fabs(sum) - 2*PI) < eps;
}

void swap(double &a, double &b){
    double tmp = a;
    a = b;
    b = tmp;
}
bool contained(point a,point b, point c){
    double x1 = a.x,
            y1 = a.y,
            x2 = b.x,
            y2 = b.y;
    if(x1 > x2)swap(x1,x2);
    if(y1 > y2)swap(y1,y2);

    return (c.x >= x1-eps && c.x <= x2+eps) && (c.y >= y1-eps && c.y <= y2+eps);
}

/**
 * Check is two line segments intersect using the left turn test
 */
bool seq_intersect(point a, point b, point c, point d){
    bool ans = (collinear(a,b,c) && contained(a,b,c)) ||
            (collinear(a,b,d) && contained(a,b,d)) ||
            (collinear(c,d,a) && contained(c,d,a)) ||
            (collinear(c,d,b) && contained(c,d,b));
    return ans || (ccw(a,b,c) != ccw(a,b,d) && ccw(c,d,a) != ccw(c,d,b));
}

/**
 * Checks if two polygons intersect
 */
bool polyintersect(const vector<point> &P1, const vector<point> &P2){

    // Test if a line segment of one of the polygons intersects a line segment in     the other polygon
    for (int i = 0; i < P1.size()-1; ++i)
        for (int j = 0; j < P2.size()-1; ++j)
            if(seq_intersect(P1[i], P1[i+1],P2[j], P2[j+1]))return true;

    // Otherwise the polygons don't intersect
    return inPolygon(P1[0], P2) || inPolygon(P2[0], P1);
}

//vector<vector<point> > m;
//int s[42];
//
//int main() {
//	int n;
//	while (scanf("%d\n", &n)) {
//		if (n == 0)
//			break;
//		int a, b;
//		MEM(s, -1);
//		m.clear();
//		for (int i = 0; i < n; i++) {
//			string line;
//			stringstream ss;
//			getline(cin, line);
//			ss.str(line);
//			vector<point> vp;
//			while (ss >> a >> b)
//				vp.push_back(point(a, b));
//			m.push_back(vp);
//		}
////
////		for (int i = 0; i < m.size(); i++){
////			for (int j = 0; j < m[i].size(); j++)
////				cout << m[i][j].x << ", " << m[i][j].y << " ";
////			cout << endl;
////		}
//
//		for (int i = 0; i < m.size(); i++)
//			for (int j = i + 1; j < m.size(); j++)
//				if (polyintersect(m[i], m[j]))
//					if (s[j] == -1)
//						s[j] = i;
//					else
//						s[i] = j;
//
//		int cnt = 0;
//		for (int i = 0; i < n; i++) {
//			if (s[i] == -1)
//				cnt++;
////			cout << s[i] << " ";
//		}
////		cout << endl;
//		cout << cnt << endl;
//	}
//
//	return 0;
//}


vector<vi> g;
vi vis;

/**
 * use DFS to find connected components
 */
void dfs(int u){
    vis[u]= 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i];
        if(!vis[v])dfs(v);
    }
}

int main(){

    int N;
    while(cin >> N && N){

        // List of polygons
        vector<vector<point> > poly(N+1,vector<point>());
        string line;getline(cin, line);

        // Input
        for (int i = 0; i < N; ++i) {
            getline(cin, line);
            stringstream ss;
            ss.str(line);
            int x,y;
            while(ss >> x >> y)
                poly[i].push_back(point(x,y));
             poly[i].push_back(poly[i][0]);
        }

        // Make each polygon a vertex in the adjacency list
        // And add an edge if two polygons intercept
        g.assign(N+1,vi());
        vis.assign(N+1,0);
        for (int i = 0; i < N; ++i) {
            for (int j = i+1; j < N; ++j) {
                if(polyintersect(poly[i],poly[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        // Count connected components
        int ans = 0;
        for (int i = 0; i < N; ++i)
        if(!vis[i])
            dfs(i),ans++;

        cout << ans << endl;
    }

    return 0;
}
