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

int res[40][40], mf, f, s, t, total;
vi p;

void augment(int v, int minEdge){
	if (v == s) {
		f = minEdge;
//		cout << "f: " << f << endl;
		return;
	}
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int main(){
	ifstream is;
	string line;
	s = 0;
	t = 37;
    for(;;) {
        if(getline(cin, line) == 0) break;
		mf = 0;
		total = 0;
		MEM(res, 0);
        do {
            if(line.size() == 0) break;
            res[0][line[0] - 'A' + 1] = line[1] - '0';
			total += line[1] - '0';
			int i = 2;
			while (line[++i] != ';')
				res[line[0] - 'A' + 1][line[i] - '0' + 27] = INF;
        } while(getline(cin, line));

		for (int i = 27; i < 37; i++)
			res[i][t] = 1;

		while (1) {
			f = 0;
			vi dist(40, INF);
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			p.assign(40, -1);
			while (!q.empty()){
				int u = q.front(); q.pop();
				if (u == t)
					break;
				for (int v = 0; v < 38; v++)
					if (res[u][v] > 0 && dist[v] == INF){
						dist[v] = dist[u] + 1, q.push(v), p[v] = u;
					}
			}
			augment(t, INF);
			if (f == 0)
				break;
			mf += f;
		}
		if (total != mf)
			cout << "!";
		else
			for (int i = 27; i < 37; i++)
				for (int j = 1; j < 38; j++)
					if (res[i][j] > 0)
						if (j == 37)
							cout << "_";
						else cout << (char)(j - 1 + 'A');
		cout << endl;
	}
	return 0;
}
