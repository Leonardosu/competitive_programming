#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;

string impar,par;
string ans,number;

int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	while(n--)
	{
		ans = "";
		impar = par = "";

		cin>>number;
		for(auto e : number)
		{
			int x = e - '0';
			if(e%2)
				impar+=e;
			else
				par+=e;
		}
		
		int a = 0,b = 0;
		
		for(int i=0;i<number.size();++i)
		{
			int x = impar[a] - '0';
			int y = par[b] - '0';
			if(x < y)
				ans+=impar[a],a++;
			else
				ans+=par[b],b++;

			if(a == impar.size())
			{
				while(b < par.size())
					ans+=par[b],b++;
				break;
			}
			
			else if(b == par.size())
			{
				while(a < impar.size())
					ans+=impar[a],a++;
				break;
			}
		}
		
		if(par.size() == 0)
			ans = impar;
		if(impar.size() == 0)
			ans = par;
		
		cout<<ans<<"\n";

	}
}