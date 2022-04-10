#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
int q;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>q;
	while(q--)
	{
		int b,carne,frang;
		int p1,p2;
 
		int ans = 0;
		cin>>b>>carne>>frang;
		cin>>p1>>p2;
		if(p1>p2)
		{
			int qnt = 0;
 
			qnt = b/2;
			ans+=min(qnt,carne)*p1;
 
			b-=min(qnt,carne)*2;
			qnt = b/2;
 
			ans+=min(qnt,frang)*p2;		
		}
		else
		{
			int qnt = 0;
			qnt = b/2;
 
			ans+=min(qnt,frang)*p2;
 
			b-=min(qnt,frang)*2;
			qnt = b/2;
 
			ans+=min(qnt,carne)*p1;
 
		}
		cout<<ans<<"\n";
	}
}