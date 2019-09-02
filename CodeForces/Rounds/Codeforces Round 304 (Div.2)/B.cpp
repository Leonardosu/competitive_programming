#include <bits/stdc++.h> // Greedy solution
using namespace std;

vector<int> v;
int ans = 0;
int n,x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x; v.push_back(x);
	}

	sort(v.begin(),v.end());


	for(int i=1;i<v.size();++i)
	{
		while(v[i] <= v[i-1])
			v[i]++,ans++;
	}

	cout<<ans<<"\n";
}