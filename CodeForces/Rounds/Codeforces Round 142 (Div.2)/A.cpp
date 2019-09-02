#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef pair<int,int> ii;
 
vector<ii> dragons;
int n,k;
int a,b;
bool possible=true;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	cin>>k>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a>>b;
		dragons.pb(mp(a,b));
	}
 
	sort(dragons.begin(),dragons.end());
 
	for(int i=0;i<dragons.size();++i)
	{
		if(dragons[i].f>=k)
		{
			possible=false;
			break;
		}
		else
			k+=dragons[i].s;
	}
 
	if(possible)
		cout<<"YES\n";
	else
		cout<<"NO\n";
}