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
	string s = "dir1\n dir11\n dir12\n  picture.jpeg\n  dir121\n  file1.txt\ndir2\n file2.gif\n";
	string images[3] = {"jpeg", "gif", "png"};
	vector<string> stk;
	int i = 0, j;
	int spc = 0;
	int stklen = 0, maxlen = 0;
	for (; i < s.size();) {
		stringstream ss("");
		int dir = 1, img = 0, space = 0;
		for (j = i; j < s.size(); j++) {
			if (s[j] == ' ') {
				space++;
				continue;
			}
			if (s[j] == '.') {
				ss << s[j];
				dir = 0;
				int k = j+1;
				stringstream ss1("");
				for (; k < s.size(); k++) {
					if ('a' <= s[k] && s[k] <= 'z')
						ss1 << s[k];
					else break;
				}
				string tmp1 = ss1.str();
				for (int l = 0; l < 3; l++)
					if (images[l] == tmp1) {
						img = 1;
						ss << tmp1;
					}
				j = k-1;
				continue;
			}
			if (s[j] == '\n') {
				string tmp = ss.str();
				if (dir) {
					if (space > spc) {
						stk.push_back(tmp);
						stklen += tmp.size() + 1;
						spc++;
					}
					else {
						while (spc > space) {
							stklen -= (stk.back().size() + 1);
							stk.pop_back();
							spc--;
						}
						if (stk.size() > 0) {
							stklen -= (stk.back().size() + 1);
							stk.pop_back();
							spc--;
						}
						stk.push_back(tmp);
						stklen += tmp.size() + 1;
					}
					break;
				}
				if (img) {
					int len = stklen + tmp.size() + 1;
					maxlen = max(maxlen, len);
					break;
				}
				break;
			}
			else
				ss << s[j];
		}
		i = j+1;
	}
	cout << maxlen << endl;
	return 0;
}
