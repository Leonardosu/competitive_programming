#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define N
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
 
int R[3];
int t,n,x;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>x;
		R[x%2]++;
	}
 
	int ans = 0;
 
	if(R[0] > R[1])
		ans = R[1];
	else
		ans = R[0];
	
	cout<<ans<<"\n";
}