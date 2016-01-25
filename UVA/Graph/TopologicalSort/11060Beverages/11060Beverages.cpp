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

map<int,int>indegree;
map<int,int>taken;
vector<int>depends[110];
vector<int>result;

int main(){
	map<string,int>index;
	map<int,string>index2;
	int num,match,i,j,k,indx,cs=1;
	string s,s2;
	while(cin>>num)
	{
	   indx=0;
	   for(i=1;i<=num;i++)
	   {
		   cin>>s;
			index[s]=++indx;
			index2[indx]=s;
	   }
	   cin>>match;
	   for(i=1;i<=match;i++)
	   {
		   cin>>s>>s2;
		   indegree[index[s2]]++;
		   depends[index[s]].push_back(index[s2]);
	   }

	for(i=1;i<=num;i++)
		for(j=1;j<=num;j++)
			if(!indegree[j] && !taken[j])
			{
				taken[j]=1;
				result.push_back(j);
				for(k=0;k<depends[j].size();k++)
				indegree[depends[j][k]]--;
				break;
			}
	cout<<"Case #"<<cs<<": Dilbert should drink beverages in this order: ";
	for(i=0;i<result.size()-1;i++)
	cout<<index2[result[i]]<<" ";
	cout<<index2[result[i]]<<"."<<endl<<endl;
	indegree.clear();
	taken.clear();
	result.clear();
	for(i=1;i<=num;i++)
		depends[i].clear();
		cs++;
	}

	return 0;
}
