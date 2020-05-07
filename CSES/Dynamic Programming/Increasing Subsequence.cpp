#include <bits/stdc++.h> //O(N.LogN)
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 2e5 + 7;

int n,x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	
	vector<int> v;
	for(int i=0;i<n;++i)
	{
		cin>>x;

		auto y = lower_bound(all(v),x);
		if(y == v.end())
			v.push_back(x);
		else
			*y = x;
	}

	cout<<v.size()<<"\n";	
}