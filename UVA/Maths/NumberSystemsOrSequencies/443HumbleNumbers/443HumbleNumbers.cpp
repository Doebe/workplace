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
	int n, cnt = 0;
	priority_queue<int> pq;
	vi all;
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 14; j++){
			for (int k = 0; k < 20; k++){
				for (int l = 0; l < 31; l++){
					ll product = pow(2, l) * pow(3, k) * pow(5, j) * pow(7, i);
					if (product > 2000000000) break;
//					cout << product << endl;
					pq.push(-product);
				}
			}
		}
	}
	while (!pq.empty()){
		if (all.size() == 0 || all[all.size()-1] != -pq.top())
			all.push_back(-pq.top());
		pq.pop();
	}
	while (cin >> n){
		if (n == 0)
			break;
		if (n % 100 / 10 == 1)
			printf("The %dth humble number is %d.\n", n, all[n]);
		else if (n % 10 == 1)
			printf("The %dst humble number is %d.\n", n, all[n]);
		else if (n % 10 == 2)
			printf("The %dnd humble number is %d.\n", n, all[n]);
		else if (n % 10 == 3)
			printf("The %drd humble number is %d.\n", n, all[n]);
		else
			printf("The %dth humble number is %d.\n", n, all[n]);
	}
	return 0;
}
