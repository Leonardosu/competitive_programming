#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef pair<int,int> ii;
typedef long long int ll;

ll gcd(ll a,ll b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

int t;
int n,k,ans;

int solve(int x) 
{ 
  	int ans = x;

  	for(int i=2;i*i<=x;++i)
  	{
  		if(i > k) break;
  		if(x%i == 0)
		{
			ans = min(ans,x/i);
	  		int y = x/(x/i);
			if((x/i) <= k) ans = min(ans,y);
  		}
  	}
  	      
    return ans; 
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ans = 0;

		if(n <= k)
		{
			cout<<"1\n";
			continue;
		}

		cout<<solve(n)<<'\n';
		
	}

}