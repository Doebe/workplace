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
//typedef pair<int,int> ii;
//typedef pair<int,char> ic;
//typedef pair<long,char> lc;
//typedef vector<int> vi;
//typedef vector<ii> vii;
//
//int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
//int lcm(int a,int b){return a*(b/gcd(a,b));}
//
//int n, m, adj[52][52], r[] = {0, -1, 0, 1}, c[] = {-1, 0, 1, 0};
//map<string, int> dir;
//
//bool valid(int x, int y){
//	bool self, left, up, upleft;
//	self = x >= 0 && x < n && y >= 0 && y < m && adj[x][y] == 0;
//	left = x >= 0 && x < n && y-1 >= 0 && y-1 < m && adj[x][y-1] == 0;
//	up = x-1 >= 0 && x-1 < n && y >= 0 && y < m && adj[x-1][y] == 0;
//	upleft = x-1 >= 0 && x-1 < n && y-1 >= 0 && y-1 < m && adj[x-1][y-1] == 0;
////	cout << self << left << up << upleft << endl;
//	return self && left && up && upleft;
//}
//
//int main(){
//	dir["west"] = 0;
//	dir["north"] = 1;
//	dir["east"] = 2;
//	dir["south"] = 3;
//	while (cin >> n >> m){
//		MEM(adj, -1);
//		if (n == 0)
//			break;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				cin >> adj[i][j];
//		ii s, t;
//		string direction;
//		cin >> s.first >> s.second >> t.first >> t.second >> direction;
//
//		if (!valid(s.first, s.second)||!valid(t.first, t.second)){
//			cout << -1 << endl;
//			continue;
//		}
//
//		int dist[n][m];
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < m; j++)
//				dist[i][j] = INF;
//
//		dist[s.first][s.second] = 0;
//		priority_queue<pair<ii, ii>, vector<pair<ii, ii> >, greater<pair<ii, ii> > > q; q.push(make_pair(ii(0, dir[direction]), s));
//
//		bool found = false;
//		while (!q.empty()){
////			cout << 1 << endl;
//			pair<ii, ii> cur = q.top(); q.pop();
//			ii u = cur.second; int d = cur.first.second; int dis = cur.first.first;
////			cout << u.first << " " << u.second << " " << d << dis << endl;
//			if (dis > dist[u.first][u.second]) continue;
//			for (int i = 0; i < 4; i++){
//				for (int j = 1; j <= 3; j++){
//					int u1 = u.first+j*r[i], u2 = u.second+j*c[i];
//					if (!valid(u1, u2)){
////						cout << u1 << " " << u2 << endl;
//						break;
//					}
//					if (i == d){
//						if (dist[u1][u2] > dist[u.first][u.second] + 1){
//							dist[u1][u2] = dist[u.first][u.second] + 1;
//							q.push(make_pair(ii(dist[u1][u2], i), ii(u1, u2)));
//						}
//					}
//					else {
//						if (dist[u1][u2] > dist[u.first][u.second] + 3 - (abs(i - d) % 2)){
//							dist[u1][u2] = dist[u.first][u.second] + 3 - (abs(i - d) % 2);
//							q.push(make_pair(ii(dist[u1][u2], i), ii(u1, u2)));
//						}
//					}
////					cout << u1 << " " << u2 << " " << i << " " << dist[u1][u2] << endl;
//					if (u1 == t.first && u2 == t.second)
//						found = true;
//				}
//			}
//		}
////		cout << endl;
////		for (int i = 0; i < n; i++){
////			for (int j = 0; j < m; j++)
////				cout << dist[i][j] << " ";
////			cout << endl;
////		}
//		if (found)
//			cout << dist[t.first][t.second] << endl;
//		else cout << -1 << endl;
//	}
//	return 0;
//}

#include<cstdio>
#include<queue>
using namespace std;
struct nodo {
	int x, y, dir, time;
	nodo(int a, int b, int c, int d) {
		x = a;
		y = b;
		dir = c;
		time = d;
	}
};
int M, N;
int di[] = { -1, 0, 1, 0 };
int dj[] = { 0, 1, 0, -1 };
bool obstacle[50][50];
bool visited[51][51][4];
bool valido(int x, int y) {
	if (x <= 0 || y <= 0 || x >= M || y >= N)
		return false;
	if (obstacle[x - 1][y - 1])
		return false;
	if (obstacle[x - 1][y])
		return false;
	if (obstacle[x][y - 1])
		return false;
	if (obstacle[x][y])
		return false;
	return true;
}
int shortest_time(int &startx, int &starty, int &dir, int &endx, int &endy) {
	queue<nodo> Q;
	if (valido(startx, starty)) {
		Q.push(nodo(startx, starty, dir, 0));
		visited[startx][starty][dir] = true;
	}
	while (!Q.empty()) {
		nodo aux = Q.front();
		Q.pop();
		if (aux.x == endx && aux.y == endy)
			return aux.time;
		if (!visited[aux.x][aux.y][(aux.dir + 1) % 4]) {
			visited[aux.x][aux.y][(aux.dir + 1) % 4] = true;
			Q.push(nodo(aux.x, aux.y, (aux.dir + 1) % 4, aux.time + 1));
		}
		if (!visited[aux.x][aux.y][(aux.dir + 3) % 4]) {
			visited[aux.x][aux.y][(aux.dir + 3) % 4] = true;
			Q.push(nodo(aux.x, aux.y, (aux.dir + 3) % 4, aux.time + 1));
		}
		for (int i = 1; i <= 3; i++) {
			if (valido(aux.x + di[aux.dir] * i, aux.y + dj[aux.dir] * i)) {
				if (visited[aux.x + di[aux.dir] * i][aux.y + dj[aux.dir] * i][aux.dir])
					continue;
				visited[aux.x + di[aux.dir] * i][aux.y + dj[aux.dir] * i][aux.dir] =
						true;
				Q.push(
						nodo(aux.x + di[aux.dir] * i, aux.y + dj[aux.dir] * i,
								aux.dir, aux.time + 1));
			} else
				break;
		}
	}
	return -1;
}
int main() {
	int startx, starty, endx, endy, dir, ax;
	char s[6];
	while (1) {
		scanf("%d %d", &M, &N);
		if (M == 0 || N == 0)
			break;
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++) {
				scanf("%d", &ax);
				obstacle[i][j] = ax;
			}
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				fill(visited[i][j], visited[i][j] + 4, false);
		scanf("%d %d %d %d %s", &startx, &starty, &endx, &endy, s);
		if (s[0] == 'n')
			dir = 0;
		else if (s[0] == 'e')
			dir = 1;
		else if (s[0] == 's')
			dir = 2;
		else
			dir = 3;
		printf("%d\n", shortest_time(startx, starty, dir, endx, endy));
	}
	return 0;
}
