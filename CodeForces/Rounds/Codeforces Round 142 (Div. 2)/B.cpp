#include <bits/stdc++.h>
#define MAXN 1000000
using namespace std;
 
typedef long long int ll;
set<ll> tprimos;
 
ll number,x,root;
int n;
 
bool primo(ll x) 
{
    for (int i = 2; i * i <= x; ++ i)
    {    	
        if (x % i == 0) 
        {
            return false;    
        }
    }
    return true;
}
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	for(ll i=3;i<=MAXN;i+=2)
		if(primo(i))
			tprimos.insert(i*i);
 
	tprimos.insert(4);
 
	cin>>n;
 
	while(n--)
	{
		cin>>x;
		if(tprimos.find(x) != tprimos.end())
			cout<<"YES\n";	
		else
			cout<<"NO\n";
	}
}