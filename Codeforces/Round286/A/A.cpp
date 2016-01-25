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

string line;
bool isPalin(int i, int j){
	while (i <= j){
		if (line[i++] != line[j--])
			return false;
	}
	return true;
}

int main(){
	getline(cin, line);
	int i = 0, j = line.size()-1;
	bool p = true;
	bool palin = true;
	ic letter(0, line[0]);
	while (i < j){
		if (line[i] == line[j]){
			i++;
			j--;
			if (i >= j)
				letter = ic(j, line[j]);
			continue;
		}
		if (!isPalin(i+1, j) && !isPalin(i, j-1)){
			p = false;
			break;
		}
		if (isPalin(i+1, j))
			letter = ic(j, line[i]);
		else letter = ic(i-1, line[j]);
		break;
	}
	if (!p)
		cout << "NA" << endl;
	else {
		string ans = "";
		for (int k = 0; k <= letter.first; k++)
			ans += line[k];
		ans += letter.second;
		for (int k = letter.first+1; k < line.size(); k++)
			ans += line[k];
		cout << ans << endl;
	}
}
