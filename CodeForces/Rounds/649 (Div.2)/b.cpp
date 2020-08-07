#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 1e5 + 7;
int v[maxn];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;	
		for(int i=1;i<=n;++i)
			cin>>v[i];

		ll sum = 0,now = 0;
		int ini = 1,fim = -1;
		vector<int> ans;
		ans.push_back(v[1]);

		for(int i=2;i<=n-1;++i)
		{
			if(v[i-1] < v[i] ^ v[i] < v[i+1])
				ans.push_back(v[i]);
		}

		ans.push_back(v[n]);
		
		cout<<ans.size()<<"\n";
		for(int &x : ans)
			cout<<x<<" ";
		cout<<"\n";
	}

}