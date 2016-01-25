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
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

#define MAXV 50

vector < int > edges[MAXV + 1];
int connected[MAXV + 1][MAXV + 1];
int degree[MAXV + 1];
int parent[MAXV + 1];

int find(int x){
    return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
}

void eulerian_cycle(int begin){
    for (int to = 1; to <= MAXV; to++)
        if (connected[begin][to]){
            connected[begin][to]--;
            connected[to][begin]--;

            eulerian_cycle(to);

            cout << to << " " << begin << "\n";
        }
}

bool breadth_first_search(int begin){
    bool discovered[MAXV + 1];

    for (int c = 1; c <= MAXV; c++)
        discovered[c] = (edges[c].size() == 0);

    queue < int > q;
    q.push(begin);

    while (!q.empty()){
        int vertex = q.front();
        q.pop();

        for (int v = 0; v < edges[vertex].size(); v++)
            if (discovered[edges[vertex][v]] == false){
                q.push(edges[vertex][v]);
                discovered[edges[vertex][v]] = true;
            }
    }

    for (int c = 1; c <= MAXV; c++)
        if (discovered[c] == false)
            return true;

    return false;
}

void solve_by_breadth_first_search(void)
{
    int number = 1, cases;
    int n;
    int cleft, cright;

    cin >> cases;
    while (cases--){
        memset(connected, 0, sizeof(connected));

        for (int c = 1; c <= MAXV; c++)
            edges[c].clear();

        cin >> n;
        for (int c = 1; c <= n; c++){
            cin >> cleft >> cright;

            edges[cleft].push_back(cright);
            edges[cright].push_back(cleft);

            connected[cleft][cright]++;
            connected[cright][cleft]++;
        }

        int begin = 1;
        while (!edges[begin].size())
            begin++;

        bool impossible = breadth_first_search(begin);

        if (!impossible){
            for (int c = 1; c <= MAXV; c++)
                if (edges[c].size() & 1){
                    impossible = true;
                    break;
                }
        }

        cout << "Case #" << number++ << endl;
        if (impossible)
            cout << "some beads may be lost" << endl;
        else
            eulerian_cycle(begin);
        cout << endl;
    }
}

// ?
void solve_by_union_find(void)
{
    int number = 1, cases;  // ?
    int n;          // ?
    int cleft, cright;  // ?

    cin >> cases;
    while (cases--)
    {
        memset(connected, 0, sizeof(connected));
        memset(degree, 0, sizeof(degree));

        for (int c = 1; c <= MAXV; c++)
            parent[c] = c;

        cin >> n;
        for (int c = 1; c <= n; c++)
        {
            cin >> cleft >> cright;

            connected[cleft][cright]++;
            connected[cright][cleft]++;

            degree[cleft]++;
            degree[cright]++;

            //  cleft  cright ??
            // ?
            int pleft = find(cleft);
            int pright = find(cright);

            if (pleft != pright)
                parent[pleft] = pright;
        }


        bool impossible = false;

        // ? 0 ?
        int begin = 1;
        while (!degree[begin])
            begin++;

        int tparent = find(begin);
        for (int c = 1 + begin; c <= MAXV; c++)
            if (degree[c] && find(c) != tparent)
            {
                impossible = true;
                break;
            }

        // ?
        if (!impossible)
        {
            for (int c = 1; c <= MAXV; c++)
                if (degree[c] & 1)
                {
                    impossible = true;
                    break;
                }
        }

        cout << "Case #" << number++ << "\n";

        if (impossible)
            cout << "some beads may be lost\n";
        else
            eulerian_cycle(begin);

        if (cases)
            cout << "\n";
    }
}

int main(int ac, char *av[])
{
    // ?UVa RT 0.556s?
    solve_by_breadth_first_search();

    // ?UVa RT 0.560s?
    // solve_by_union_find();

    return 0;
}
