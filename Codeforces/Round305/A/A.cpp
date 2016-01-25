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

typedef pair<int,int> ii;
typedef long long ll;
typedef pair<int,char> ic;
typedef pair<long,char> lc;
typedef vector<char> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

string line;

bool isPalin(const string &s){
    int i = 0, j= s.size() -1;
    while(i<j){
        if(s[i++] != s[j--])return false;
    }
    return true;
}

int main(){
    string line;
    int n,i=0, start=-1;
    cin >> line >> n;

    if(line.size() % n == 0){
        int len = line.size() / n;
        for (i = 0,start = 0; i < n; ++i, start += len) {
            if(!isPalin(line.substr(start, len))){
                break;
            }
        }
    }

    if(i == n){
        cout << "YES";
    }else
        cout << "NO";
    cout << endl;

    return 0;
}
