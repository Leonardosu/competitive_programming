#include <bits/stdc++.h> //	O(N*Log(N))
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

int n;
vector<int> v;

int lis(vector<int> &v)
{
	vector<int> p;

	for(auto e : v)
	{
		auto x = lower_bound(all(p),e);
		if(x == p.end())
			p.pb(e);
		else
			*x = e;		
	}
	return (int)p.size();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;

	v.resize(n);
	for(int i=0;i<n;++i)
		cin>>v[i];

	cout<<lis(v)<<"\n";
}