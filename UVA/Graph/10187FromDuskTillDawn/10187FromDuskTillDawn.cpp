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
typedef pair<string, int> si;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef map<pair<si, si>, int> msisi;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int n, c, begin, last;
	string start, end;
	si stt, tmn;
//	while ( scanf ("%d %d", &n, &k) != EOF ) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		msisi list;
		while (c--){
			cin >> start >> end >> begin >> last;
			begin %= 24;
			int final = (begin + last)%24;
			if ((begin > 6 && begin < 18) || last > 12 || (final > 6 && final < 18))
				continue;
			stt = si(start, begin);
			tmn = si(end, final);
			list[pair<si, si>(stt, tmn)] = 0;
		}
		cin >> start >> end;

		map<string, int> dist;
		for(msisi::const_iterator it = list.begin(); it != list.end(); ++it ){
		      pair<si,si> key = it->first;
		      dist[key.second.first] = INF;
//		      cout << key.first.first << ", " << key.first.second << ", "
//		    		  << key.second.first << ", " << key.second.second << ", "
//					  << it->second << endl;
		}
		dist[start] = 0;

		priority_queue<pair<si, int> > pq;
		pq.push(pair<si, int>(si(start, 18), 0));
		while (!pq.empty()){
//			for(map <string, int>::const_iterator it = dist.begin(); it != dist.end(); ++it ){
//				cout << it->first << ", " << it->second << endl;
//			}
			pair<si, int> front = pq.top();
			pq.pop();
			si u = front.first;
			int d = front.second;
			if (d > dist[u.first]) continue;
			for(msisi::const_iterator it = list.begin(); it != list.end(); ++it ){
				pair<si, si> ele = it->first;
				if (ele.first.first != u.first) continue;
				if (u.first == end) continue;
				int bag = 0;
				if ((ele.first.second <= 6 && u.second <= 6) || (ele.first.second >= 18 && u.second >= 18)){
					if (ele.first.second < u.second)
						bag++;						;
				}
				else if (u.second <= 6)
					bag++;					;
				pair<si, int> v = pair<si, int>(ele.second, bag);
				if (dist[u.first] + v.second < dist[v.first.first]){
					dist[v.first.first] = dist[u.first] + v.second;
					pq.push(v);
				}
			}
		}
		int rst = INF;
		cout << "Test Case " << i+1 << "." << endl;
		if (dist.count(end)){
			rst = min(rst, dist[end]);
			if (rst == INF)
				cout << "There is no route Vladimir can take." << endl;
			else cout << "Vladimir needs " << rst << " litre(s) of blood." << endl;
		}else cout << "There is no route Vladimir can take." << endl;
	}
	return 0;
}

