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

int n, y[28][28], m[28][28];

int main(){
	while (cin >> n){
		if (n == 0)
			break;
		for (int i = 0; i < 28; i++)
			for (int j = 0; j < 28; j++){
				if (i == j)
					y[i][j] = 0;
				else y[i][j] = 1000;
			}
		for (int i = 0; i < 28; i++)
			for (int j = 0; j < 28; j++){
				if (i == j)
					m[i][j] = 0;
				else m[i][j] = 1000;
			}
		char a, b, c, d;
		int e;
		while (n--){
			cin >> a >> b >> c >> d >> e;
			if (a == 'Y'){
				y[c - 'A'][d - 'A'] = min(e, y[c - 'A'][d - 'A']);
				if (b == 'B')
					y[d - 'A'][c - 'A'] = e;
			} else {
				m[c - 'A'][d - 'A'] = min(e, m[c - 'A'][d - 'A']);
				if (b == 'B')
					m[d - 'A'][c - 'A'] = e;
			}
		}

		for (int k = 0; k < 28; k++)
			for (int i = 0; i < 28; i++)
				for (int j = 0; j < 28; j++)
					y[i][j] = min(y[i][j], y[i][k] + y[k][j]);

		for (int k = 0; k < 28; k++)
			for (int i = 0; i < 28; i++)
				for (int j = 0; j < 28; j++)
					m[i][j] = min(m[i][j], m[i][k] + m[k][j]);

		cin >> a >> b;
		vi cur;
		pair<int, vi> mini = pair<int, vi>(1000, cur);
		for (int i = 0; i < 28; i++)
			if (y[a - 'A'][i] != 1000 && m[b - 'A'][i] != 1000){
				int temp = y[a - 'A'][i] + m[b - 'A'][i];
				if (mini.first > temp){
					mini.first = temp;
					vi newCur;
					newCur.push_back(i);
					mini.second = newCur;
				} else if (mini.first == temp)
					mini.second.push_back(i);
			}
		if (mini.first == 1000)
			cout << "You will never meet." << endl;
		else {
			sort(mini.second.begin(), mini.second.end());
			cout << mini.first << " ";
			for (int i = 0; i < mini.second.size(); i++){
				cout << (char)(mini.second[i] + 'A');
				if (i != mini.second.size() - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
