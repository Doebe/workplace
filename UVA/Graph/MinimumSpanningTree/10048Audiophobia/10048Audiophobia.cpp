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

int d [100 + 5] [100 + 5];

void reset (int c){
    for ( int i = 0; i <= c; i++ )
        for ( int j = 0; j <= c; j++ )
            d[i][j] = INF;
}

int main ()
{
    int c, s, q;
    int cases = 0;
    bool blank = false;

    while (scanf("%d %d %d", &c, &s, &q)) {
        if ( c == 0 && s == 0 && q == 0 ) break;
        reset (c);
        int c1, c2, deci;

        for ( int i = 0; i < s; i++ ) {
            scanf ("%d %d %d", &c1, &c2, &deci);
            d[c1][c2] = d[c2][c1] = deci;
        }

        for ( int k = 1; k <= c; k++ )
            for ( int i = 1; i <= c; i++ )
                for ( int j = 1; j <= c; j++ )
                    d[i][j] = d[j][i] = min(d[i][j], max(d[i][k], d[k][j]));

        if ( blank ) printf ("\n");
        blank = true;

        printf ("Case #%d\n", ++cases);

        for ( int i = 0; i < q; i++ ) {
            scanf ("%d %d", &c1, &c2);
            if (c1 <= 0 || c1 > c || c2 <= 0 || c2 > c) printf ("%d\n" , 0);
            else if ( d[c1][c2] == INF ) printf ("no path\n");
            else printf ("%d\n", d[c1][c2]);
        }
    }

    return 0;
}
//
//int C, S, Q, x, y, z, a, b, mst_cost;
//map<int, vii> adj;
//map<int, vii> parent;
//vi taken;
//priority_queue<pair<int, ii> > pq;
//
//class UnionFind{
//private: vi p, rank;
//public:
//	UnionFind(int N){
//		rank.assign(N, 0);
//		p.assign(N, 0);
//		for(int i = 0; i < N; i++)
//			p[i] = i;
//	}
//	int findSet(int i){
//		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
//	}
//	bool isSameSet(int i, int j){
//		return findSet(i) == findSet(j);
//	}
//	void unionSet(int i, int j){
//		if (!isSameSet(i, j)){
//			int x = findSet(i), y = findSet(j);
//			if (rank[x] > rank[y]) p[y] = x;
//			else {
//				p[x] = y;
//				if (rank[x] == rank[y]) rank[y]++;
//			}
//		}
//	}
//};
//
//void process(int vtx){
//	taken[vtx] = 1;
//	for (int j = 0; j < (int)adj[vtx].size(); j++){
//		ii v = adj[vtx][j];
//		if (!taken[v.first]) pq.push(make_pair(-v.second, ii(vtx, v.first)));
//	}
//}
//
//int main(){
//	int caseNum = 1;
//	while (cin >> C >> S >> Q){
//		if (C == 0)
//			break;
//		for (int i = 1; i <= C; i++){
//			vii l;
//			adj[i] = l;
//		}
//		int total = 0;
//		for (int i = 0; i < S; i++){
//			cin >> x >> y >> z;
//			total += z;
//			adj[x].push_back(ii(y, z));
//			adj[y].push_back(ii(x, z));
//		}
////		for (int i = 0; i < m; i++){
////			cout << i << ": ";
////			for (int j = 0; j < adj[i].size();j++){
////				cout << adj[i][j].first << "," << adj[i][j].second << " ";
////			}
////			cout << endl;
////		}
//		taken.assign(C + 1, 0);
//		for (int i = 1; i <= C; i++){
//			vii p;
//			parent[i] = p;
//		}
//		for (int i = 1; i <= C; i++){
//			if (!taken[i]){
//				process(i);
//				vii l;
//				l.assign(C + 1, ii(-1, 0));
//				parent[i] = l;
//			}
//			while(!pq.empty()){
//				pair<int, ii> front = pq.top(); pq.pop();
//				int w = -front.first;
//				int u = front.second.first;
//				int v = front.second.second;
//				if (!taken[v]){
//					parent[i][v] = ii(u, w);
//					process(v);
//				}
//			}
//		}
//		if (caseNum > 1)
//			cout << endl;
//		cout << "Case #" << caseNum++ << endl;
//		for (int i = 0; i < Q; i++){
//			bool found = false;
//			int maxi = 0;
//			cin >> a >> b;
//			for (int j = 1; j <= C; j++){
//				UnionFind UF(C + 1);
//				if (parent[j].size() == 0)
//					continue;
//				for (int k = a; k != -1; k = parent[j][k].first){
//					maxi = max(maxi, parent[j][k].second);
//					if (parent[j][k].first != -1)
//						UF.unionSet(k, parent[j][k].first);
////					cout << k << " and " << parent[j][k].first << " " << UF.isSameSet(a, b) << endl;
////					cout << UF.findSet(a) << " " << UF.findSet(b) << endl;
//					if (UF.isSameSet(a, b)){
//						found = true;
//						break;
//					}
//				}
//				if (!found){
////					UnionFind UF(C + 1);
//					for (int k = b; k != -1; k = parent[j][k].first){
//						maxi = max(maxi, parent[j][k].second);
//						UF.unionSet(k, parent[j][k].first);
////						cout << k << " and " << parent[j][k].first << " " << UF.isSameSet(a, b) << endl;
////						cout << UF.findSet(a) << " " << UF.findSet(b) << endl;
//						if (UF.isSameSet(a, b)){
//							found = true;
//							break;
//						}
//					}
//				}
//			}
//			if (!found)
//				cout << "no path" << endl;
//			else cout << maxi << endl;
//		}
//	}
//	return 0;
//}
