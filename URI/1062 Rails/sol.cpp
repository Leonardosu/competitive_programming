/*	
	1062 - Rails
	Leonardo Su
*/
#include <bits/stdc++.h>

using namespace std;

int n,x,y;
bool flag;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n && n)
	{
		while(cin>>y)
		{
			int id = n;
			vector<int> v;
			stack<int> trens;

			if(y == 0) break;

			v.push_back(y);
			for(int i=0;i<n-1;++i)
			{
				cin>>x; v.push_back(x);
			}

			for(int i=v.size()-1;i>=0;--i)
			{
				// cout<<"#";
				x = v[i];
				// cout<<x<<" ";

				if(x == id)
					id--;
				else
				{
					flag = true;

					while(!trens.empty() && flag)
					{						
						flag = false;
						if(trens.top() == id)
							trens.pop(),id--,flag = true;
					}

					trens.push(x);

					flag = true;
					while(!trens.empty() && flag)
					{
						flag = false;
						if(trens.top() == id)
							trens.pop(),id--,flag = true;
					}					
				}
			}

			flag = true;
			while(!trens.empty() && flag)
			{
				flag = false;
				if(trens.top() == id)
					trens.pop(),id--,flag = true;
			}	

			if(!trens.empty()) cout<<"No\n";
			else cout<<"Yes\n";
		}

		cout<<"\n";
	}
}
