#include <bits/stdc++.h> //Greedy O(N*LogN)
using namespace std;

int n,x,y;
long long int ans;
multiset<int> bills;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	while(cin>>n && n)
	{
		bills.clear();
		ans = 0;

		for(int i=1;i<=n;++i)
		{
			cin>>x;
			for(int j=1;j<=x;++j)
			{
				cin>>y;
				bills.insert(y);
			}

			auto a = bills.begin();
			auto b = bills.end();
			b--;
			bills.erase(a);
			bills.erase(b);
			
			ans += *b - *a;
		}
		cout<<ans<<"\n";
	}

}