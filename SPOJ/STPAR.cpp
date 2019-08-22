/*
	STPAR - Street Parade
	Leonardo Su
	O(NlogN) *Stack*
*/

#include <bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n && n)
	{
		int id = 1;	bool change = true;
		stack<int> trens;
		vector<int> ans;

		for(int i=1;i<=n;++i)
		{
			cin>>x;
			if(x == id)
			{
				ans.push_back(x);
				id++;
				continue;
			}

			change = true;

			while(!trens.empty() && change)
			{
				change = false;
				if(trens.top() == id)
				{
					ans.push_back(id);					
					id++,trens.pop(),change = true;				

				}
			}

			trens.push(x);
			change = true;

			while(!trens.empty() && change)
			{
				change = false;
				if(trens.top() == id)
				{
					ans.push_back(id);					
					id++,trens.pop(),change = true;				
				}
			}
		}

		change = true;


		while(!trens.empty() && change)
		{
			change = false;
			if(trens.top() == id)
			{
				ans.push_back(id);					
				id++,trens.pop(),change = true;				
			}
		}
		
		bool sorted = true;
		for(int i=0;i<ans.size()-1;++i)
			if(ans[i]+1 != ans[i+1])
			{
				sorted = false;
				break;
			}
		if(!trens.empty() || !sorted) cout<<"no\n";
		else cout<<"yes\n";
		
	}
}