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
typedef vector<pair<int, string> > vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int m;
string s, t;
map<string, int> m1;
map<int, string> m2;
map<int, vi> adj;
int main(){
	while (scanf("%d\n", &m)){
		if (m == 0)
			break;
		string line;
		getline(cin, line);
		stringstream ss;
		ss.str(line);
		ss >> s >> t;
//		scanf("%s %s", &s, &t);
		string i1, i2, p;
		while (m--){
			getline(cin, line);
			stringstream ss;
			ss.str(line);
			ss >> i1 >> i2 >> p;
			if (!m1.count(i1)){
				m1[i1] = m2.size();
				m2[m1[i1]] = i1;
			}
			if (!m1.count(i2)){
				m1[i2] = m2.size();
				m2[m1[i2]] = i2;
			}
			adj[m1[i1]].push_back(make_pair(m1[i2], p));
			adj[m1[i2]].push_back(make_pair(m1[i1], p));
		}
		if (!m1.count(t))
			printf("impossivel\n");
		else{
			map<char, int> dis;
			for (char i = 'a'; i <= 'z'; i++)
				dis[i] = INF;
			map<int, map<char, int> > dist;
			for (int i = 0; i < m1.size(); i++)
				dist[i] = dis;
	//		vector<pair<int, char> > dist(m1.size(), make_pair(INF,''));
			for (char i = 'a'; i <= 'z'; i++)
				dist[m1[s]][i] = 0;
			priority_queue<pair<ii, char>, vector<pair<ii, char> >, greater<pair<ii, char> > > pq;
			pq.push(make_pair(ii(0, m1[s]), '!'));
			while (!pq.empty()){
				pair<ii, char> front = pq.top(); pq.pop(); //greedy: get shortest unvisited vertex
				int d = front.first.first, u = front.first.second;
				if (u == m1[t])
					break;
	//			printf("%d %d %c\n", d, u, front.second);
				int prev;
				if (front.second == '!')
					prev = 0;
				else prev = dist[u][front.second];
				if (d > prev) continue;	//important check
				for (int j = 0; j < (int)adj[u].size(); j++){
					pair<int, string> v = adj[u][j];	//all outgoing edges from u
					if (v.second[0] == front.second) continue;
					if (prev + v.second.size() < dist[v.first][v.second[0]]){
						dist[v.first][v.second[0]] = prev + v.second.size();	//relax operation
						pq.push(make_pair(ii(dist[v.first][v.second[0]], v.first), v.second[0]));
					}
				}
			}	//this variant can cause duplicate items in the priority queue

			int mini = INF;
			for (char i = 'a'; i <= 'z'; i++)
				mini = min(mini, dist[m1[t]][i]);
			if (mini == INF)
				printf("impossivel\n");
			else printf("%d\n", mini);
		}
	}
}
