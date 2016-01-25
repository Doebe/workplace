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

int adj[102][102];
int flag[102][102];

int MST(int N, vector<pair<int, ii> > EdgeList){
	int mst = 0;
	UnionFind UF(N+1); //all V are disjoint sets initially
	for (int i = 0; i < EdgeList.size(); i++){
		pair<int, ii> front = EdgeList[i];
		int u = front.second.first, v = front.second.second;
		if (!UF.isSameSet(u, v)){
			mst += front.first; //add the weight of e to MST
			flag[u][v] = flag[v][u] = 1;
			UF.unionSet(u, v); //link them
		}
	} //the number of disjoint sets must eventually be 1 for a valid MST
	return mst;
}

int MST2(int N, vector<pair<int, ii> > EdgeList){
	int mst = 0;
	UnionFind UF(N+1); //all V are disjoint sets initially
	int S = N;
	for (int i = 0; i < EdgeList.size(); i++){
		pair<int, ii> front = EdgeList[i];
		int u = front.second.first, v = front.second.second;
		if (flag[u][v] == 2 || flag[v][u] == 2)
			continue;
		if (!UF.isSameSet(u, v)){
			mst += front.first; //add the weight of e to MST
			UF.unionSet(u, v); //link them
			S--;
		}
	} //the number of disjoint sets must eventually be 1 for a valid MST
	if (S > 1)
		return INF;
	return mst;
}

int main(){
	int T, N, M, A, B, C;
	cin >> T;
	while (T--){
		cin >> N >> M;
		MEM(adj, 0);
		MEM(flag, 0);
		for (int i = 0; i < M; i++){
			cin >> A >> B >> C;
			if (adj[A][B] == 0)
				adj[A][B] = C;
			else adj[A][B] = min(adj[A][B], C);
			if (adj[B][A] == 0)
				adj[B][A] = C;
			else adj[B][A] = min(adj[B][A], C);
		}
//		for (int i = 1; i <= N; i++){
//			for (int j = 1; j <= N; j++)
//				cout << adj[i][j] << " ";
//			cout << endl;
//		}
		vector<pair<int, ii> > EdgeList;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (adj[i][j] > 0)
					EdgeList.push_back(make_pair(adj[i][j], ii(i, j)));
			}
		}
		sort(EdgeList.begin(), EdgeList.end());	//sort by edge weight
//		for (int i = 0; i < EdgeList.size(); i++){
//			cout << EdgeList[i].second.first << " --> " << EdgeList[i].second.second << ": " << EdgeList[i].first << endl;
//		}
		printf("%d ", MST(N, EdgeList));
		int mini = INF;
		for (int i = 1; i <= N; i++){
			for (int j = 1; j <= N; j++){
				if (flag[i][j] == 0)
					continue;
				flag[i][j] = flag[j][i] = 2;
				mini = min(mini, MST2(N, EdgeList));
				flag[i][j] = flag[j][i] = 1;
			}
		}
		printf("%d\n", mini);
	}
	return 0;
}
