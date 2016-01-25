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

ll _sieve_size;
bitset<10000010> bs;
map<int, int> primes;
//map<int, int> parent;

void sieve(ll upperbound){
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++)
		if (bs[i]){
			for (ll j = i * i; j <= _sieve_size; j+=i)
				bs[j] = 0;
			if (i >= 1000 && i <= 9999) {
				primes[(int)i] = -1;
//				parent[(int)i] = -1;
			}
		}
}

int main(){
	sieve(9999);
	int c, a, b;
//	a = 1019;
//	for (int i = 1; i <= 4; i++) {
//		int dgt = a % (int)pow(10, i) / (int)pow(10, i-1);
//		for (int j = 0; j < 10; j++) {
//			if (i == 4 && j == 0)
//				continue;
//			int dif = j - dgt;
//			if (dif == 0)
//				continue;
//			int num = a + dif * (int)pow(10, i-1);
//			if (num == b) {
//				primes[num] = primes[a] + 1;
////						parent[num] = top;
//				break;
//			}
//			printf("digit : %d, dgt : %d, newdgt : %d, num : %d.\n", i, dgt, j, num);
//		}
//	}
//	return 0;
	scanf("%d", &c);
	while (c--) {
		scanf("%d %d", &a, &b);
		if (!primes.count(a) || !primes.count(b)) {
			printf("Impossible\n");
			continue;
		}
		int ans = 0;
		for (map<int, int>::iterator it = primes.begin(); it != primes.end(); it++)
			it->second = -1;
//		for (map<int, int>::iterator it = parent.begin(); it != parent.end(); it++)
//			it->second = -1;
		queue<int> q;
		primes[a] = 0;
		q.push(a);
		while (!q.empty()) {
			int top = q.front(); q.pop();
			if (top == b)
				break;
			for (int i = 1; i <= 4; i++) {
				int dgt = top % (int)pow(10, i) / (int)pow(10, i-1);
				for (int j = 0; j < 10; j++) {
					if (i == 4 && j == 0)
						continue;
					int dif = j - dgt;
					if (dif == 0)
						continue;
					int num = top + dif * (int)pow(10, i-1);
					if (num == b) {
						primes[num] = primes[top] + 1;
//						parent[num] = top;
						break;
					}
//					printf("digit : %d, dgt : %d, newdgt : %d, num : %d.\n", i, dgt, newdgt, num);
					if (!primes.count(num))
						continue;
					if (primes[num] != -1)
						continue;
					primes[num] = primes[top] + 1;
//					parent[num] = top;
					q.push(num);
				}
				if (primes[b] != -1)
					break;
			}
			if (primes[b] != -1)
				break;
		}
		int tmp = b;
//		cout << parent[b] << endl;
//		while (parent[tmp] != -1) {
//			printf("parent of %d is %d.\n", tmp, parent[tmp]);
//			tmp = parent[tmp];
//		}
		if (primes[b] == -1)
			printf("Impossible\n");
		else printf("%d\n", primes[b]);
	}
	return 0;
}
