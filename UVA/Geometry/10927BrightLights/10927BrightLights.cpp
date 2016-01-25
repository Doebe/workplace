#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();
const int INF = 1000000000;
const int NEG_INF = -1000000000;

#define max(a,b)((a)>(b)?(a):(b))
#define min(a,b)((a)<(b)?(a):(b))
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI acos(0)*2.0
#define eps 1.0e-11
#define are_equal(a,b)fabs(a-b)<eps
#define LS(b)(b& (-b)) // Least significant bit
#define DEG_to_RAD(a)((a*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef pair<double, double> dd;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

struct point{
	int x, y, z;
	point(int _x, int _y, int _z) : x(_x), y(_y), z(_z){}
	bool operator < (point other) const{
		return sqrt(pow(x, 2)+pow(y, 2)) > sqrt(pow(other.x, 2)+pow(other.y, 2));
	}
};

int c, n, x, y, z;
map<ii, int> m;
vector<ii> rst;

int main(){
	c = 0;
	while (true){
		c++;
		cin >> n;
		if (n == 0)
			break;
		m.clear();
		rst.clear();
		priority_queue<point> pq;
		int yl = -1;
		int yr = -1;
		int x0 = -1;
		while (n--){
			cin >> x >> y >> z;
			pq.push(point(x, y, z));
		}
		while (!pq.empty()){
			point cur = pq.top();
			pq.pop();
//			cout << cur.x << " " << cur.y << endl;
			if (cur.x == 0){
				if (cur.z <= x0)
					rst.push_back(ii(cur.x, cur.y));
				else x0 = cur.z;
			}
			else if (cur.y == 0 && cur.x < 0){
				if (cur.z <= yl)
					rst.push_back(ii(cur.x, cur.y));
				else yl = cur.z;
			}
			else if (cur.y == 0 && cur.x > 0){
				if (cur.z <= yr)
					rst.push_back(ii(cur.x, cur.y));
				else yr = cur.z;
			}
			else {
				ii k = ii(cur.y / gcd(cur.y, cur.x), cur.x / gcd(cur.y, cur.x));
				if (m.count(k) != 0){
					if (cur.z <= m[k])
						rst.push_back(ii(cur.x, cur.y));
					else m[k] = cur.z;
				} else m[k] = cur.z;
			}
		}

		cout << "Data set " << c << ":" << endl;
		sort(rst.begin(), rst.end());
		if (rst.size() == 0)
			cout << "All the lights are visible." << endl;
		else {
			cout << "Some lights are not visible:" << endl;
			for (int i = 0; i < rst.size(); i++){
				cout << "x = " << rst[i].first << ", y = " << rst[i].second;
				if (i == rst.size()-1)
					cout <<"." << endl;
				else cout <<";" << endl;
			}
		}
	}
}
