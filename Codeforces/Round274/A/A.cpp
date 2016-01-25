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

int main(){
	int t, n, cs = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		string line;
		map<string, int> m1;
		map<int, string> m2;

		getline(cin, line);
		for (int i = 0; i < n; i++){
			getline(cin, line);
			m1[line] = m2.size();
			m2[m1[line]] = line;
		}
		vi q;
		for (int i = 0; i < n; i++){
			getline(cin, line);
			q.push_back(m1[line]);
//			cout << "m1: " << m1[line] << endl;
		}
		int prev = -1;
		vi ans;
		while (!q.empty()){
			int cur;
			if (prev == -1){
				prev = cur = q[q.size()-1]; q.pop_back();
//				cout << prev << " " << cur << q.size() << endl;
//				cout << cur << " " << m1.size() - 1;
				if (cur < m1.size()-1){
					ans.push_back(cur);
					for (int i = 0; i < q.size(); i++){
						ans.push_back(q[q.size()-1-i]);
					}
					break;
				}
			}
			else {
				cur = q[q.size()-1]; q.pop_back();
//				cout << cur << " " << prev << endl;
				if (prev < cur){
					ans.push_back(cur);
					for (int i = 0; i < q.size(); i++){
						ans.push_back(q[q.size()-1-i]);
					}
					break;
				}
				prev = cur;
			}
		}
		for (int i = 0; i < ans.size(); i++)
			printf("%s\n", m2[ans[i]].c_str());
		printf("\n");
	}
}
