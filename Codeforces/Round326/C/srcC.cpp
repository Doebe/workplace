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
//  cout << 1000000 << endl;
//  for (int i = 0; i < 1000000; i++)
//      cout << i << endl;
//  return 0;
    int n, w;
    scanf("%d", &n);
//  map<int, int> m;
    int m[1000010];
    MEM(m, 0);
    for (int i = 0; i < n; i++) {
    	scanf("%d", &w);
        m[w]++;
    }

    int cnt = 0;
    for (int i = 0; i < 1000010; i++) {
        if (m[i] % 2)
            cnt++;
        m[i+1] += m[i]/2;
    }
//  for (int i = 0; i < 8; i++)
//      cout << m[i] << " ";
//  cout << endl;
    printf("%d\n", cnt);
    return 0;
}
