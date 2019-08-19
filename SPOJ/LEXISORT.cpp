/*
	LEXISORT SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
vector<string> v;
string frase;
int t,n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;

	while(t--)
	{
		cin>>n; v.clear();
		for(int i=0;i<n;++i)
		{
			cin>>frase;
			v.pb(frase);
		}

		sort(v.begin(),v.end());
		for(int i=0;i<n;++i)
			cout<<v[i]<<"\n";
	}
}