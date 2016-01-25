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

/*
int matrix[20][20], memo[200][20];
int n, m, c, k, rst;

int findMax(int layer, int total){

	if (total < 0)
		return -100000;
	if (layer == c)
		return m - total;
	if (memo[total][layer] != -1)
		return memo[total][layer];
	int ans = -1;
	for (int i = 1; i <= matrix[layer][0]; i++){
		ans = max(ans, findMax(layer+1, total-matrix[layer][i]));
	}
	return memo[total][layer] = ans;
}

int main(){
	scanf("%d", &n);
	while (n--){
		rst = 0;
		scanf("%d %d", &m, &c);
		for (int i = 0; i < c; i++){
			scanf("%d", &k);
			matrix[i][0] = k;
			for (int j = 1; j <= k ; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		MEM(memo, -1);
		rst = findMax(0, m);
		if (rst >= 0)
			printf("%d\n", rst);
		else
			printf("no solution\n");
	}

	return 0;
}
*/

int M, C, price[25][25];
int memo[210][25];
int shop(int money, int g){
	if (money < 0) return -10000000;
	if (g == C) return M - money;
	if (memo[money][g] != -1) return memo[money][g];
	int ans = -1;
	for (int model = 1; model <= price[g][0]; model++)
		ans = max(ans, shop(money - price[g][model], g + 1));
	return memo[money][g] = ans;
}

int main(){
	int i, j, TC, score;
	scanf ("%d", &TC);
	while (TC-->0){
		scanf("%d %d", &M, &C);
		for (i = 0; i < C; i++){
			scanf("%d", &price[i][0]);
			for (j = 1; j<= price[i][0]; j++)
				scanf("%d", &price[i][j]);
		}
		memset(memo, -1, sizeof memo);
		score = shop(M, 0);
		if (score < 0) printf("no solution\n");
		else printf("%d\n", score);
	}
}
