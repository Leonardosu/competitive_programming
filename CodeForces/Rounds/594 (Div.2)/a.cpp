#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
 
const int N = 100010;
const int INF = 1e9;
 
typedef pair<int,int> ii;
typedef long long int ll;
 
 
ll ans = 0;
ll impar1,impar2;
ll par1,par2;
ll x;
int t;
int q,p;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)
	{
		cin>>q;
		ans = 0;
		impar1 = impar2 = 0;
		par1 = par2 = 0;
		
		for(int i=0;i<q;++i)
		{
			cin>>x;
			if(x%2 == 1)
				impar1++;
			else
				par1++;
		}
 
		cin>>p;
		for(int i=0;i<p;++i)
		{
			cin>>x;
			if(x%2 == 1)
				impar2++;
			else
				par2++;
		}
 
		ans = par1*par2 + impar1*impar2;
		cout<<ans<<"\n";
	}
}	