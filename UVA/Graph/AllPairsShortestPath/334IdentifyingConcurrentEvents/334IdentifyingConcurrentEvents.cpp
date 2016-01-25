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

int NC, NE, NM, before[1000][1000], after[1000][1000];
map<int, string> mis;
map<string, int> msi;

int main(){
	int c = 0;
	while (cin >> NC){
		if (NC == 0)
			break;
		mis.clear();
		msi.clear();
		MEM(before, 0);
		MEM(after, 0);
		for (int nc = 0; nc < NC; nc++){
			cin >> NE;
			string input[NE];
			for (int ne = 0; ne < NE; ne++){
				cin >> input[ne];
				if (!msi.count(input[ne]))
					msi[input[ne]] = mis.size();
				mis[msi[input[ne]]] = input[ne];
			}
			for (int i = 0; i < NE; i++)
				for (int j = i + 1; j < NE; j++){
					before[msi[input[i]]][msi[input[j]]] = 1;
					after[msi[input[j]]][msi[input[i]]] = 1;
				}
		}

		cin >> NM;
		string a, b;
		while (NM--){
			cin >> a >> b;
			before[msi[a]][msi[b]] = 1;
			after[msi[b]][msi[a]] = 1;
		}

		for (int k = 0; k < msi.size(); k++)
			for (int i = 0; i < msi.size(); i++)
				for (int j = 0; j < msi.size(); j++){
					before[i][j] |= (before[i][k] & before[k][j]);
					after[i][j] |= (after[i][k] & after[k][j]);
				}

		int cnt = 0;
		vii output;
		for (int i = 0; i < msi.size(); i++){
			for (int j = i + 1; j < msi.size(); j++){
				if (i == j)
					continue;
				if ((before[i][j] || after[i][j]) == 0){
					if (cnt < 2)
						output.push_back(ii(i, j));
					cnt++;
				}
			}
		}
		printf("Case %d, ", ++c);
		if (cnt == 0)
			printf("no concurrent events.\n");
		else {
			printf("%d concurrent events:\n", cnt);
			if (cnt == 1)
				printf("(%s,%s) \n", mis[output[0].first].c_str(), mis[output[0].second].c_str());
			else printf("(%s,%s) (%s,%s) \n", mis[output[0].first].c_str(),
					mis[output[0].second].c_str(), mis[output[1].first].c_str(),
					mis[output[1].second].c_str());
		}
	}
	return 0;
}
