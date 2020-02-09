#include <bits/stdc++.h> 
using namespace std;

int n,ans,x,q,cnt,last;
map<int,int> dic;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>q;
	while(q--)
	{
		ans = cnt = last = 0;
		dic.clear();
		cin>>n;

		for(int i=1;i<=n;++i)
		{
			cin>>x;
				
			if(dic[x] > last)
			{
				cnt = i - dic[x];
				last = dic[x];
			}
			else
				cnt++;

			dic[x] = i;
			ans = max(ans,cnt);
		}

		cout<<ans<<"\n";
	}
}