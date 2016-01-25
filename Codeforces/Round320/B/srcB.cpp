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
typedef pair<int, ii> iii;
typedef vector<iii> viii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

using namespace std;

int main() {
    int n, a;
    cin >> n;
    int used[1000];
    MEM(used, 0);
    priority_queue<iii> pq;
    for (int i = 2; i <= 2*n; i++) {
        for (int j = 1; j < i; j++) {
            cin >> a;
            pq.push(iii(a, ii(i, j)));
        }
    }
    while (!pq.empty()) {
        int p1 = pq.top().second.first;
        int p2 = pq.top().second.second;
        pq.pop();
        if (!used[p1] && !used[p2]) {
            used[p1] = p2;
            used[p2] = p1;
        }
    }
    for (int i = 1; i <= 2*n; i++) {
        cout << used[i] << " ";
    }
    return 0;
}
