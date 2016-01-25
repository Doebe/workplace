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
typedef pair<int, int> ii;
typedef pair<int, char> ic;
typedef pair<long, char> lc;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * (b / gcd(a, b));
}

typedef struct All {
	int First, Second;
	double Cost;
} E;

class UnionFind{
private: vi p, rank;
public:
	UnionFind(int N){
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++)
			p[i] = i;
	}
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j){
		if (!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) p[y] = x;
			else {
				p[x] = y;
				if (rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int Cmp(const void* X, const void* Y) {
	if (((E*) X)->Cost < ((E*) Y)->Cost)
		return -1;
	if (((E*) X)->Cost > ((E*) Y)->Cost)
		return 1;
	return 0;
}

bool Comp(const E &a, const E &b) {
	return a.Cost < b.Cost;
}

int TestCases;
int Cities, State, First, Second;
int X[5000], Y[5000];
vector<E> V;

int main(int argc, char** argv) {
// freopen("Trojan.txt", "r", stdin);
	int Cases = 1;
	scanf("%d", &TestCases);
	while (TestCases--) {
		V.clear();
		scanf("%d %d", &Cities, &State);
		int Index = 0;
		for (int i = 0; i < Cities; i++)
			scanf("%d %d", &X[i], &Y[i]);
		for (int i = 0; i < Cities; i++) {
			for (int j = i + 1; j < Cities; j++) {
				V.push_back(E());
				V[Index].First = i;
				V[Index].Second = j;
				V[Index].Cost = hypot(X[i] - X[j], Y[i] - Y[j]);
				Index++;
			}
		}
		UnionFind UF(Cities);
		int mst_cost = 0;
		int StatesCounter = 1;
		double Roads = 0;
		double RailRoads = 0;
		sort(V.begin(), V.end(), Comp);
		for (int i = 0; i < V.size(); i++) {
			if (!UF.isSameSet(V[i].First, V[i].Second)) {
				UF.unionSet(V[i].First, V[i].Second);
				if (V[i].Cost > State)
					RailRoads += V[i].Cost, StatesCounter++;
				else
					Roads += V[i].Cost;
			}
		}
		printf("Case #%d: %d %.lf %.lf\n", Cases++, StatesCounter, Roads,
				RailRoads);
	}
	return 0;
}
