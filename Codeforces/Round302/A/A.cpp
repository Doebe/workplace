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
	int k;
	scanf("%d\n", &k);
	string line;
	getline(cin, line);
	vi letters(26, 0);
	string ss = "";
	vector<string> ans;
	for (int i = 0; i < line.size(); i++){
//		cout << i << " " << ss << endl;
		if (ss.size() == 0 || ss[ss.size()-1] == line[i]){
			ss += line[i];
			letters[line[i]-'a'] = 1;
			continue;
		}
		if (letters[line[i]-'a'] == 1){
			ss += line[i];
			continue;
		}
		ans.push_back(ss);
		ss = line[i];
		letters[line[i]-'a'] = 1;
	}
	ans.push_back(ss);
	if (ans.size() < k){
		printf("NO\n");
	}else{
		printf("YES\n");
		int i;
		for (i = 0; i < k - 1; i++)
			printf("%s\n", ans[i].c_str());
		string last = "";
		for (int j = i; j < ans.size(); j++)
			last += ans[j];
		printf("%s\n", last.c_str());
	}

}
