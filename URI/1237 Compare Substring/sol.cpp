/*	
	1237 - Compare Substring
	Leonardo Su
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define MAXN 55
using namespace std;

string A,B;
int n,q,data[MAXN][MAXN];
int x,maior;

int lcs(int a,int b)
{
	if(a<0 || b<0 || A[a]!=B[b])  return 0;
	if(data[a][b]!=-1) return data[a][b];
	if(A[a]==B[b])
	 	return data[a][b]=1+lcs(a-1,b-1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
  
	while(getline(cin,A))
	{
	  	maior=0;
		getline(cin,B);
		memset(data,-1,sizeof data);
		
		for(int i=0;i<A.size();++i)
			for(int j=0;j<B.size();++j)
				maior=max(maior,lcs(i,j));
		cout<<maior<<"\n";
	}
  
  return 0;
}