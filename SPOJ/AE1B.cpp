/*
	AE1B SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int n,k,s;
int a,sum,total;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>n>>k>>s;
	total=k*s;

	for(int i=0;i<n;++i)
	{
		cin>>a;
		v.pb(-a);
	}

	sort(v.begin(),v.end());

	for(int i=0;i<v.size();++i)
	{
		sum-=v[i]; 
		if(sum >= total)
			{cout<<i + 1<<"\n"; break;}
	}
}