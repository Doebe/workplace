#include <bits/stdc++.h>
using namespace std;

const int INF = std::numeric_limits<int>::max() / 3;

#define MEM(arr,val)memset((arr),(val), sizeof (arr))
#define PI (acos(0)*2.0)
#define eps (1.0e-9)
#define are_equal(a,b)fabs((a)-(b))<eps
#define abs_val(a)((a)>=0)?(a):(-(a))
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a * (b / gcd(a, b));
}

/**
 * __builtin_popcount(int d) // count bits
 * strtol(s, &end, base); // convert base number
 */
//----------------------------------------------------------------------//
class Rect {
public:
	int x0, x1, y0, y1;
	Rect() {
		x0 = x1 = y0 = y1 = 0;
	}
	void debug() {
		printf("(%d %d) (%d %d)\n", x0, y0, x1, y1);
	}
};

int W, H, N;
int xx0, yy0, xx1, yy1;

vector<Rect> X;

void update(Rect a) {
	xx0 = min(xx0, a.x0);
	yy0 = min(yy0, a.y0);
	xx1 = max(xx1, a.x1);
	yy1 = max(yy1, a.y1);
}

pair<Rect, Rect> HorCutT(Rect r, int y) {

	Rect a, b;
	a.x0 = r.x0;
	a.x1 = r.x1;
	a.y0 = r.y0;
	a.y1 = y;
	b.x0 = r.x0;
	b.x1 = r.x1;
	b.y1 = y;
	b.y0 = 2 * y - (r.y1);
	return pair<Rect, Rect>(a, b);
}

Rect reflectT(Rect a, int y) {
	int ny0 = 2 * y - a.y1;
	int ny1 = 2 * y - a.y0;
	a.y0 = ny0;
	a.y1 = ny1;
	return a;
}

pair<Rect, Rect> HorCutB(Rect r, int y) {

	Rect a, b;
	a.x0 = r.x0;
	a.x1 = r.x1;
	a.y0 = y;
	a.y1 = r.y1;
	b.x0 = r.x0;
	b.x1 = r.x1;
	b.y1 = 2 * y - r.y0;
	b.y0 = y;
	return pair<Rect, Rect>(a, b);
}

Rect reflectB(Rect a, int y) {
	int ny0 = 2 * y - a.y1;
	int ny1 = 2 * y - a.y0;
	a.y0 = ny0;
	a.y1 = ny1;
	return a;
}

pair<Rect, Rect> VerCutL(Rect r, int y) {

	Rect a, b;
	a.x0 = y;
	a.x1 = r.x1;
	a.y0 = r.y0;
	a.y1 = r.y1;
	b.x0 = y;
	b.x1 = 2 * y - r.x0;
	b.y1 = r.y1;
	b.y0 = r.y0;
	return pair<Rect, Rect>(a, b);
}

Rect reflectL(Rect a, int y) {
	int nx0 = 2 * y - a.x1;
	int nx1 = 2 * y - a.x0;
	a.x0 = nx0;
	a.x1 = nx1;
	return a;
}

pair<Rect, Rect> VerCutR(Rect r, int y) {

	Rect a, b;
	a.x0 = r.x0;
	a.x1 = y;
	a.y0 = r.y0;
	a.y1 = r.y1;
	b.x0 = 2 * y - r.x1;
	b.x1 = y;
	b.y1 = r.y1;
	b.y0 = r.y0;
	return pair<Rect, Rect>(a, b);
}

Rect reflectR(Rect a, int y) {
	int nx0 = 2 * y - a.x1;
	int nx1 = 2 * y - a.x0;
	a.x0 = nx0;
	a.x1 = nx1;
	return a;
}


int main() {
	FASTER;

	while(cin >> W >> H >> N, (W || H || N)) {
		X.clear();
		Rect r;

		xx0 = INF;
		yy0 = INF;
		xx1 = -INF;
		yy1 = -INF;

		r.x0 = 0, r.y0 = 0, r.x1 = W, r.y1 = H;
		X.push_back(r);
		update(r);
		for (int i = 0; i < N; ++i) {
//			printf("i = %d\n",i);
			char C;int K;
			cin >> C >> K;
			vector<Rect> Y;
			if(C =='T') {
				int y = yy1 - K;

				for (int j = 0; j < X.size(); ++j) {
					if(y < X[j].y1 && y > X[j].y0 ) {
						pair<Rect,Rect> res = HorCutT(X[j], y);
						Y.push_back(res.first);
						Y.push_back(res.second);
						update(res.first);
						update(res.second);
					} else if(y <= X[j].y0) {
						Rect temp = reflectT(X[j],y);
						update(temp);
						Y.push_back(temp);
					} else if(y >= X[j].y1) {
						Y.push_back(X[j]);
					}
				}

			} else if(C == 'B') {
				int y = yy0 + K;

				for (int j = 0; j < X.size(); ++j) {
					if(y < X[j].y1 && y > X[j].y0 ) {
						pair<Rect,Rect> res = HorCutB(X[j], y);
						Y.push_back(res.first);
						Y.push_back(res.second);
						update(res.first);
						update(res.second);
					} else if(y >= X[j].y0) {
						Rect temp = reflectB(X[j],y);
						update(temp);
						Y.push_back(temp);
					} else if(y <= X[j].y1) {
						Y.push_back(X[j]);
					}
				}

			} else if (C == 'L') {
				int y = xx0 + K;

				for (int j = 0; j < X.size(); ++j) {
					if(y < X[j].x1 && y > X[j].x0 ) {
						pair<Rect,Rect> res = VerCutL(X[j], y);
						Y.push_back(res.first);
						Y.push_back(res.second);
						update(res.first);
						update(res.second);
//						res.first.debug();
//						res.second.debug();
					} else if(y >= X[j].x1) {
						Rect temp = reflectL(X[j],y);
						update(temp);
						Y.push_back(temp);
//						temp.debug();
					} else if(y <= X[j].x0) {
						Y.push_back(X[j]);
//						X[j].debug();
					}
				}

			} else if(C == 'R') {
				int y = xx1 - K;
				for (int j = 0; j < X.size(); ++j) {
					if(y < X[j].x1 && y > X[j].x0 ) {
						pair<Rect,Rect> res = VerCutR(X[j], y);
						Y.push_back(res.first);
						Y.push_back(res.second);
						update(res.first);
						update(res.second);
//						res.first.debug();
//						res.second.debug();
					} else if(y <= X[j].x0) {
						Rect temp = reflectR(X[j],y);
						update(temp);
						Y.push_back(temp);
//						temp.debug();
					} else if(y >= X[j].x1) {
						Y.push_back(X[j]);
//						X[j].debug();
					}
				}

			}

			X = Y;

			xx0 = INF;
			yy0 = INF;
			xx1 = -INF;
			yy1 = -INF;

			for (int j = 0; j < X.size(); ++j)
				update(X[j]);

			for (int j = 0; j < X.size(); ++j) {
				X[j].x0 -= xx0;
				X[j].x1 -= xx0;
				X[j].y0 -= yy0;
				X[j].y1 -= yy0;
			}
			xx1 -= xx0;
			xx0 -= xx0;
			yy1 -= yy0;
			yy0 -= yy0;

//			printf("%d %d %d %d\n", xx0, yy0, xx1, yy1);
//			for (int j = 0; j < X.size(); ++j) {
//				X[j].debug();
//			}
		}

		int x, y;
		cin >> x >> y;
		int cnt = 0;



		for (int i = 0; i < X.size(); ++i) {
			if(x >= X[i].x0 && x <= X[i].x1 && y >= X[i].y0 && y <= X[i].y1 )cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}
