#include <bits/stdc++.h>
using namespace std;

const int  INF = std::numeric_limits<int>::max()/3;

#define max(a,b)((a)>(b)?(a):(b))
#define min(a,b)((a)<(b)?(a):(b))
#define MEM(arr,val)memset(arr,val, sizeof arr)
#define PI (acos(0)*2.0)
#define eps 1.0e-9
#define are_equal(a,b)fabs((a)-(b))<eps
#define LS(b)(b&(-(b))) // Least significant bit
#define DEG_to_RAD(a)(((a)*PI)/180.0) // convert to radians

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int gcd(int a,int b){return b == 0 ? a : gcd(b,a%b);}
int lcm(int a,int b){return a*(b/gcd(a,b));}

//----------------------------------------------------------------------//
#define MAX_SZ 120
int city_out[MAX_SZ],city_in[MAX_SZ], mat[MAX_SZ][MAX_SZ];

class Edge{
public :
    int u,v, cap,f;
    Edge(int _u, int _v, int _cap) : u(_u) , v(_v), cap(_cap){
        f = 0;
    }

    int other(int w){
        if(w == u)return v;
        return u;
    }

    int resTo(int w){
        if(w == v)return cap - f;
        return f;
    }
    int flowTo(int w){
        if(w == v)return f;
        return cap - f;
    }

    void addFlowTo(int w, int d){
        if(w == v)
            f += d;
        else
            f -= d;
    }
};

typedef vector<Edge*> edgeList;

vector<edgeList> G;
edgeList P;
vi vis;
int s,t;

bool bfs(){
    queue<int> q;
    P.assign(t+1, NULL);
    vis.assign(t+1,0);

    q.push(s);
    vis[s] = 1;

    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = 1;
        if(u == t)break;

        for (int i = 0; i < G[u].size(); ++i) {
            Edge * e = G[u][i];
            int v = e->other(u);
            if(!vis[v] && e->resTo(v) > 0){
                P[v] = e;
                q.push(v);
            }
        }
    }
    return P[t] != NULL;
}
void addEdge(int u, int v, int c){
    Edge * e = new Edge(u,v,c);
    G[u].push_back(e);
    G[v].push_back(e);
}

int main(){
    int n, m, sum_in, sum_out;
    cin >> n >> m;

    MEM(mat,0);
    MEM(city_in,0);
    MEM(city_out,0);

    sum_in = sum_out = 0;
    for (int i = 0,temp; i < n; ++i) {
        cin >> temp;city_in[i] = temp,sum_in += temp;
    }
    for (int i = 0,temp; i < n; ++i) {
        cin >> temp;city_out[i] = temp,sum_out += temp;
    }

    s = 2*n;
    t = 2*n+1;
    G.assign(t+1,edgeList());
    for (int i = 0; i < n; ++i) {
        addEdge(s,i, city_in[i]);
    }
    for (int i = 0; i < n; ++i) {
        addEdge(i+n,t, city_out[i]);
    }
    for (int i = 0; i < n; ++i) {
        addEdge(i,i+n, INF);
    }

    for (int i = 0,u,v; i < m; ++i) {
        cin >> u >> v;
        u--,v--;
        addEdge(u,v+n,INF);
        addEdge(v,u+n,INF);
    }

    int sum = 0,mf = 0;

    while(bfs()){
        int f = INF;
        for (int v = t; v != s; v = P[v]->other(v)) {
            f = min(f, P[v]->resTo(v));
        }
        mf += f;
        for (int v = t; v != s; v = P[v]->other(v)) {
            P[v]->addFlowTo(v, f);
        }
    }


    if(sum_in == sum_out && mf == sum_in){

        for (int u = 0; u < n; ++u) {
            for (int i = 0; i < G[u].size(  ); ++i) {
                Edge* e = G[u][i];
                int v = e->other(u);
                mat[u][v-n] = e->flowTo(v);
            }
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(j)cout << " ";
                cout << mat[i][j];
            }
            cout << endl;
        }
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
