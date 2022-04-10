#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 55
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
bool impossivel = false;
int A[N][N];
int B[N][N];
int n,m;
 
bool equal(int n,int m)
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(A[i][j] != B[i][j])
				return false;
	return true;
}
 
bool se_pinto(int i,int j)
{
	if(i+1>n || j+1>m) return false;
	if(A[i+1][j] == 0 || A[i][j+1] == 0 || A[i+1][j+1] == 0)
		return false;
	return true;
}
 
void color(int i,int j)
{	
	B[i][j] = B[i+1][j] = B[i][j+1] = B[i+1][j+1] = 1;
}
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>A[i][j];
 
	vector<ii> ans;
 
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			if(A[i][j] == 1 && se_pinto(i,j))
			{
				color(i,j);
				ans.pb(mp(i,j));
			}		
	}
 
	bool possivel = equal(n,m);
	if(possivel)
		{
			cout<<ans.size()<<"\n";
			for(int i=0;i<ans.size();++i)				
				cout<<ans[i].f<<" "<<ans[i].s<<"\n";
		}
	else
		cout<<"-1\n";
}