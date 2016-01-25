#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <queue>
#include <sstream>
#include <limits>
#include <algorithm>
#include <map>
using namespace std;

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

int main(){
	int n, k;
	while ( cin >> n >> k ) {
		int memo[n+1][103];
		memset(memo, 0, sizeof memo);
		for (int i = 0; i < n; i++){
			cin >> memo[i][0];
//			cout << memo[i][0] << endl;
		}

		string s;	getline(cin, s);
		for (int i = 0; i < n; i++){
			getline(cin, s);
			stringstream ss;	ss.str(s);
			int a;
			while (ss >> a){
				memo[i][a+1] = 1;
				//cout << i << ", " << a+1 << endl;
			}
		}

		map<ii, int> dist;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 101; j++){
				if (memo[i][j] == 1){
					if (j == 1)
						dist[ii(i, j)] = 0;
					else dist[ii(i, j)] = INF;
				}
			}
		}
		priority_queue<pair<int, ii> > pq;
		for (int i = 0; i < n; i++){
			if (memo[i][1] == 1)
				pq.push(pair<int, ii>(0, ii(i,1)));
		}
		while (!pq.empty()){
			pair<int,ii> front = pq.top();
			pq.pop();
			int d = front.first;
			ii u = front.second;
			if (d > dist[u]) continue;
			int ele = u.first;
			int flr = u.second;
			for (int j = 0; j < 101; j++){
				if (j == flr) continue;
				int time = abs(j - flr)*memo[ele][0];
				pair<ii, int> v = pair<ii, int>(ii(ele, j), time);
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					pq.push(pair<int, ii>(dist[v.first], ii(v.first)));
				}
			}
			for (int j = 0; j < n+1; j++){
				if (j == ele) continue;
				if (memo[j][flr] == 0) continue;
				int time = 60;
				pair<ii, int> v = pair<ii, int>(ii(j, flr), time);
				if (dist[u] + v.second < dist[v.first]){
					dist[v.first] = dist[u] + v.second;
					pq.push(pair<int, ii>(dist[v.first], ii(v.first)));
				}
				//cout << "flr  " << flr << endl;
			}
		}
		int rst = INF;
		for (int i = 0; i < n; i++){
			if (memo[i][k+1] == 0)	continue;
			rst = min(rst, dist[ii(i, k+1)]);
		}
		if (rst == INF)
			cout << "IMPOSSIBLE" << endl;
		else cout << rst << endl;
	}
	return 0;
}
