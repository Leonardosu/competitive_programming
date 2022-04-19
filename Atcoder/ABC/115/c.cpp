#include <bits/stdc++.h>
#define INF 1000000100
using namespace std;

int ans = INF;
int n,k,x;
int menor,dif;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		v.push_back(x);
	}

	sort(v.begin(),v.end());

	for(int i=0;i<v.size()-k+1;++i)
	{
		dif = v[i+k-1] - v[i];
		ans = min(ans,dif);
	}
	cout<<ans<<"\n";
}