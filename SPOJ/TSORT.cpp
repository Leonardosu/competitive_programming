/*
	TSORT SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int n,a;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a;
		v.pb(a);
	}

	sort(v.begin(),v.end());

	for(int i=0;i<v.size();++i)
		cout<<v[i]<<"\n";
}