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

int main() {
	return 0;
}
