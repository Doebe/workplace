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
typedef vector<char> vc;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

int main(){
	int t;
	scanf("%d\n", &t);
	while (t--){
		map<char, int> m;
		for (char ch = 'a'; ch <= 'z'; ch++)
			m[ch] = 0;
		string line;
		getline(cin, line);
		for (int i = 0; i < line.size(); i++)
			m[line[i]]++;
		priority_queue<ic> pq;
		for (char ch = 'a'; ch <= 'z'; ch++){
			if(m[ch] > 0)
				pq.push(ic(m[ch], ch));
		}
		string s ("");
		while (!pq.empty()){
			ic c1 = pq.top(); pq.pop();
//			cout << c1.first << c1.second << endl;
			if (pq.empty()){
				s.insert(s.end(), c1.first, c1.second);
				break;
			}
			ic c2 = pq.top(); pq.pop();
//			cout << c2.first << c2.second << endl;
			s.insert(s.end(), 1, c1.second);
			c1.first--;
			if (c1.first > 0)
				pq.push(c1);
			s.insert(s.end(), 1, c2.second);
			c2.first--;
			if (c2.first > 0)
				pq.push(c2);
		}
		if (s.size() > 1 && s[s.size()-1] == s[s.size()-2])
			printf("%d\n", -1);
		else {
			for (int i = 0; i < s.size(); i++){
				printf("%c", s[i]);
			}
			printf("\n");
		}
	}
}
