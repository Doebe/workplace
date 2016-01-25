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

int N;
char a, b, c;
string line;
stringstream ss;
vector<char> elements;
vector<vector<char> > adj;
map<char, bool> vis;

bool valid(char e) {
    for(int i = 0; i < adj[e].size(); i++)
        if(vis[adj[e][i]])
            return false;
    return true;
}

bool dfs(string path) {
    if(path.length() == elements.size()) {
        cout << path[0];
        for(int i = 1; i < path.length(); i++)
            cout << " " << path[i];
        cout << endl;
        return true;
    }
    bool ans = false;
    for(int i = 0; i < elements.size(); i++) {
        if(!vis[elements[i]]) {
            if(valid(elements[i])) {
                vis[elements[i]] = true;
                bool next = dfs(path + elements[i]);
                ans = next || ans;
                vis[elements[i]] = false;
            }
        }
    }
    return ans;
}

int main() {
    scanf("%d\n\n", &N);
    for(int T = 0;; T++) {
        if(T > 0) cout << endl;

        getline(cin, line);
        ss.clear();
        ss.str(line);
        elements.clear();
        while(ss >> a)
            elements.push_back(a);
        sort(elements.begin(), elements.end());

        getline(cin, line);
        ss.clear();
        ss.str(line);
        adj.clear();
        adj.resize(256);
        while(ss >> a >> b >> c)
            adj[a].push_back(c);

        if(!dfs(""))
            cout << "NO" << endl;
        if(!getline(cin, line)) break;
    }
}
