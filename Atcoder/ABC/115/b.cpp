#include <bits/stdc++.h>
using namespace std;

int n,x,sum,ans;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		v.push_back(x);
	}	

	sort(v.begin(),v.end());

	for(int i=0;i<v.size()-1;++i)
		ans+=v[i];
	ans+=v[n-1]/2;
	cout<<ans<<"\n";
}