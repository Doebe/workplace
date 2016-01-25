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

int T,R,C,M,N,W;
int g[102][102], v[102][102], c[102][102];

int incr[2]={1,-1};
void dfs(int x, int y){
    int i,j,m,n;
    if(v[x][y])
        return;
    v[x][y]=1;
    /*printf("dfs %d %dn",x,y);*/
    for(i=0; i<2;i++){
        for(j=0;j<2;j++){
            m = x+incr[i]*M; n = y+incr[j]*N;
            if(m>=0 && m < R && n>=0 && n<C && g[m][n]!=-1){
                /*printf("   x%d %dn",m,n);*/
                c[m][n]++;
                dfs(m,n);
            }
            m = x+incr[i]*N; n = y+incr[j]*M;
            if(m>=0 && m < R && n>=0 && n<C && g[m][n]!=-1){
                /*printf("   x%d %dn",m,n);*/
                c[m][n]++;
                dfs(m,n);
            }
        }
    }
}

int main(){
    int t,i,j,even,odd;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        /* clean-up */
        memset(v,0,sizeof v);
        memset(g,0,sizeof g);
        memset(c,0,sizeof c);
        even=odd=0;
        /* Input Begin */
        scanf("%d %d %d %d %d",&R,&C,&M,&N,&W);
        while(W--){
            scanf("%d %d",&i,&j);
            g[i][j] = -1;
        }
        /* Input end */
        dfs(0,0);
        /* Count evens and odds */
        for(i=0;i<R;i++) {
            for(j=0;j<C;j++){
                /* We counted twice */
                if(M==0||N==0||M==N)
                    c[i][j]/=2;
                /*printf("%d ",c[i][j]);*/
                if(c[i][j] || (!i && !j)) {
                    if(c[i][j] % 2 == 0) even++;
                    else odd++;
                }
            }
            /*printf("n");*/
        }
        printf("Case %d: %d %d\n",t,even,odd);
    }
    return 0;
}

//int c, R, C, M, N, W, x, y, e, o, m[102][102], v[102][102], cnt;
//queue<ii> q;
//
//void try_push(int a, int b){
//	if (0 <= a && a < C && 0 <= b && b < R && m[a][b] != -1 && v[a][b] == 0){
//		q.push(ii(a, b));
//		cnt++;
//		v[a][b] = 1;
//	}
//}
//
//int main(){
//	cin >> c;
//	for (int i = 0; i < c; i++){
//		cin >> R >> C >> M >> N >> W;
//		MEM(m, 0);
//		while (W--){
//			cin >> x >> y;
//			m[x][y] = -1;
//		}
//		e = 0;
//		o = 0;
//		q.push(ii(0, 0));
//		while (!q.empty()){
//			ii cur = q.front();
////			cout << cur.first << cur.second << endl;
//			q.pop();
//			x = cur.first;
//			y = cur.second;
//			if(m[x][y] > 0)
//				continue;
//			cnt = 0;
//			MEM(v, 0);
//			try_push(x-M, y-N);
//			try_push(x-M, y+N);
//			try_push(x+M, y-N);
//			try_push(x+M, y+N);
//			try_push(x-N, y-M);
//			try_push(x-N, y+M);
//			try_push(x+N, y-M);
//			try_push(x+N, y+M);
//			if (cnt % 2 == 0)
//				e++;
//			else o++;
//			m[x][y] = cnt;
//		}
////		for (int j = 0; j < 10; j++){
////			for (int k = 0; k < 10; k++)
////				cout << m[j][k] << " ";
////			cout << endl;
////		}
//		cout << "Case " << i + 1 << ": " << e << " " << o << endl;
//	}
//	return 0;
//}
