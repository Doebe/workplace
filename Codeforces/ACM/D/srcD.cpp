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
//int t, n, k;
//vi arr;
//int DP[1002];
//string line;
//
//class SegmentTree {		// the segment tree is stored like a heap array
//private:
//	vi st, A;
//	int n;
//	int left(int p) {
//		return p << 1;
//	}	// same as binary heap operations
//	int right(int p) {
//		return (p << 1) + 1;
//	}
//
//	void build(int p, int L, int R) {	// O(n)
//		if (L == R)		// as L == R, either one is fine
//			st[p] = L;	// store the index
//		else {			// recursively compute the values
//			build(left(p), L, (L + R) / 2);
//			build(right(p), (L + R) / 2 + 1, R);
//			int p1 = st[left(p)], p2 = st[right(p)];
//			st[p] = (A[p1] <= A[p2]) ? p1 : p2;
//		}
//	}
//
//	int rmq(int p, int L, int R, int i, int j) {	// O(log n)
//		if (i > R || j < L)
//			return -1;				// current segment outside query range
//		if (L >= i && R <= j)
//			return st[p];			// inside query range
//
//		// compute the min position in the left and right part of the interval
//		int p1 = rmq(left(p), L, (L + R) / 2, i, j);
//		int p2 = rmq(right(p), (L + R) / 2 + 1, R, i, j);
//
//		if (p1 == -1)
//			return p2;				// if we try to access segment outside query
//		if (p2 == -1)
//			return p1;					// same as above
//		return (A[p1] <= A[p2]) ? p1 : p2;			// as in build routine
//	}
//
//public:
//	SegmentTree(const vi &_A) {
//		A = _A;
//		n = (int) A.size();					// copy content for local usage
//		st.assign(4 * n, 0);			// create large enough vector of zeroes
//		build(1, 0, n - 1);							// recursive build
//	}
//	int rmq(int i, int j) {
//		return rmq(1, 0, n - 1, i, j);
//	}	// overloading
//};
//
//int main() {
//	scanf("%d", &t);
//	while (t--) {
//		scanf("%d %d\n", &n, &k);
//		getline(cin, line);
//		arr.clear();
//		MEM(DP, 0);
//		for (int i = 0; i < n; ++i)
//			arr.push_back(line[i] - '0');
//		DP[n] = 0;
//		for (int i = n - 1; i >= 0; i--) {
//			DP[i] = INF;
//			int alt = 1;
//			for (int j = i; j < n && j - i < k; j++) {
//				if (j > i && arr[j] == arr[j - 1])
//					alt = 0;
//				if (i == j)
//					DP[i] = min(DP[i], 1 + DP[j + 1]);
//				if (!alt) {
//					vi A(DP + j, DP + min(i + k - 1, n - 1) + 2);
//					SegmentTree st(A);
////					for (int z = 0; z < A.size(); z++)
////						cout << A[z] << " ";
////					cout << endl;
//					int index = st.rmq(0, min(i+k-1, n-1) - j + 1);
//					DP[i] = min(DP[i], 1 + DP[index + j]);
//					break;
//				}
//			}
//		}
//		cout << DP[0] - 1 << endl;
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

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
#define MAX_N 101000
#define LEFT(n)(n<<1)
#define RIGHT(n)((n<<1)+1)
int st[MAX_N * 4 + 1];
int dp[MAX_N];
vi A;
int N, K;
string str;

void build(int p, int L, int R) {

	if (L == R) {
		st[p] = L;
	} else {
		int mid = (L + R) >> 1;

		build(LEFT(p), L, mid);
		build(RIGHT(p), mid + 1, R);

		int p1 = st[LEFT(p)], p2 = st[RIGHT(p)];

		st[p] = (A[p1] <= A[p2]) ? p1 : p2;
	}
}

int rmq(int p, int L, int R, int l, int r) {

	if (l > R || r < L) {
		return -1;
	}

	if (l >= L && r <= R) {
		return st[p];
	}

	int mid = (l + r) >> 1;

	int p1 = rmq(LEFT(p), L, R, l, mid), p2 = rmq(RIGHT(p), L, R, mid + 1, r);

	if (p1 == -1)
		return p2;
	if (p2 == -1)
		return p1;

	return A[p1] < A[p2] ? p1 : p2;
}
int rmq(int l, int r) {
	if (l == r)
		return l;
	return rmq(1, l, r, 0, N);
}

void update(int p, int l, int r, int i, int val) {
	if (i == l && i == r) {
		A[i] = val;
		return;
	}

	int mid = (l + r) >> 1;

	if (i <= mid)
		update(LEFT(p), l, mid, i, val);
	else
		update(RIGHT(p), mid + 1, r, i, val);

	int p1 = st[LEFT(p)], p2 = st[RIGHT(p)];

	st[p] = A[p1] < A[p2] ? p1 : p2;
}
void update(int i, int val) {
	update(1, 0, N, i, val);
}

int main() {
	FASTER;

	int T;

	cin >> T;

	while(T--) {

		cin >> N >> K;
		cin >> str;

		int i,j;

		MEM(st,0);
		A.assign(N+2,INF);
		A[N] = 0;
		build(1, 0, N);

		vi sequential;

		for (i = 1; i < N; ++i) {
			if(str[i] == str[i-1]) {
				sequential.push_back(i);
			}
		}
		sequential.push_back(N);

		for (i = N-1; i >= 0; --i) {

			j = upper_bound(sequential.begin(), sequential.end(), i) - sequential.begin();
			j = sequential[j];

			if(A[i+1] + 1 < A[i]) {
				update(i, A[i+1] + 1);
			}

			int y = min(N, i+K);
			int x;
			if(j+1>y || j >= N)
			continue;

			x = rmq(j+1,y);

			if(A[x] + 1 < A[i]) {
				update(i, A[x] + 1);
			}
		}

		cout << A[0] - 1<< endl;
	}
	return 0;
}
