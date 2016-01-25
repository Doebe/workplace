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


int n, m, k;
int cnt[1<<21];
int block[100010];

struct q {
	int x, y, id;
    bool operator<(const q& b)const{
        return block[x]<block[b.x]||(block[x]==block[b.x]&&y<b.y);
    }
};

q query[100010];
int arr[100010];
ll total;

void add(int pos) {
	total += cnt[arr[pos]^k];
	cnt[arr[pos]]++;
}

void remove(int pos) {
	cnt[arr[pos]]--;
	total -= cnt[arr[pos]^k];
}

int main(){
	cin >> n >> m >> k;
	int sqn = sqrt(n+0.1);
	arr[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] ^= arr[i-1];
	}
	for (int i = 0; i <= n; i++)
		block[i] = i/sqn;
	for (int i = 0; i < m; i++) {
		cin >> query[i].x >> query[i].y;
		query[i].x--;
		query[i].id = i;
	}
	sort(query, query+m);
	ll ans[m];
	int l = 0, r = -1;
	total = 0;

	for (int i = 0; i < m; i++) {
		while (r < query[i].y) {
			r++;
			add(r);
		}
		while (r > query[i].y) {
			remove(r);
			r--;
		}
//		cout << query[i].x << " " << query[i].y << " " << query[i].id << endl;
		while (l > query[i].x) {
			l--;
			add(l);
		}
		while (l < query[i].x) {
			remove(l);
			l++;
		}
		ans[query[i].id] = total;
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << endl;
	return 0;
}
