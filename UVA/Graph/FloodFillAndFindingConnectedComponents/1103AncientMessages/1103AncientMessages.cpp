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



int N,M,A[209][209];
bool vis[209][209];
int belong[209][209];
int b[209*209];

void Init()
{
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=M*4+1;j++)
            A[i][j]=0;
    for(int i=1;i<=N;i++)
        for(int j=1,jj=1;j<=M;j++,jj+=4)
        {
            char r;
            cin>>r;
            int x;
            if(r>='a'&&r<='z')
                x=10+r-'a';
            else
                x=r-'0';
            A[i][jj]=(x/8)%2;
            A[i][jj+1]=(x/4)%2;
            A[i][jj+2]=(x/2)%2;
            A[i][jj+3]=(x/1)%2;
        }
    M*=4;
}

void Dfs0(int x,int y,int c)
{
    if(x<0||y<0||x>N+1||y>M+1)
        return ;
    if(vis[x][y])
        return ;
    if(A[x][y]!=0)
        return;
    vis[x][y]=true;
    belong[x][y]=c;
    Dfs0(x+1,y,c);
    Dfs0(x-1,y,c);
    Dfs0(x,y+1,c);
    Dfs0(x,y-1,c);
}

int Dfs1(int x,int y,int vt)
{
    int ret=0;
    if(x<0||y<0||x>N+1||y>M+1)
        return 0;
    if(vis[x][y])
        return 0;
    if(A[x][y]!=1)
    {
        if(b[belong[x][y]]!=vt)
            ret++;
        b[belong[x][y]]=vt;
        return ret;
    }
    vis[x][y]=true;
    ret+=Dfs1(x+1,y,vt);
    ret+=Dfs1(x-1,y,vt);
    ret+=Dfs1(x,y+1,vt);
    ret+=Dfs1(x,y-1,vt);
    return ret;
}

void Solve()
{
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=M+1;j++)
            vis[i][j]=false;
    int SpaceNum=0;
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=M+1;j++)
            if(A[i][j]==0)
                Dfs0(i,j,++SpaceNum);
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=M+1;j++)
            vis[i][j]=false;
    vector<char> Answer;
    Answer.clear();
    int vt=0;
    for(int i=1;i<=SpaceNum;i++)
        b[i]=-1;
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=M+1;j++)
            if(A[i][j]==1)
            {
                int t=Dfs1(i,j,vt++);
                if(t==1)
                    Answer.push_back('W');
                if(t==2)
                    Answer.push_back('A');
                if(t==3)
                    Answer.push_back('K');
                if(t==4)
                    Answer.push_back('J');
                if(t==5)
                    Answer.push_back('S');
                if(t==6)
                    Answer.push_back('D');
            }
    sort(Answer.begin(),Answer.end());
    for(int i=0;i<Answer.size();i++)
        cout<<Answer[i];
    cout<<"\n";
}


int main()
{
    int Case=0;
    while(cin>>N>>M&&(N||M))
    {
        Init();
        cout<<"Case "<<++Case<<": ";
        Solve();
    }
    return 0;
}
