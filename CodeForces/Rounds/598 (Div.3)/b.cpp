#include <bits/stdc++.h>
using namespace std;

const int N = 120;

bool mark[N];
int ans[N];
int q,n;

void reset()
{
	for(int i=0;i<=n;++i)
		mark[i] = false;
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>q;
	while(q--)
	{
		reset();
		cin>>n;

		for(int i=1;i<=n;++i)
			cin>>ans[i];
		int restante = n;

		for(int i=1;i<=n;++i)
		{
			if(restante == 0)
				break;

			for(int j=1;j<=n;++j)
			{
				if(ans[j] == i)
				{
					int l = 0;
					while(j-l-1>=i && !mark[j-l-1] && restante > 0 && ans[j-l-1] > ans[j-l])
						{
							int aux = ans[j-l];
							ans[j-l] = ans[j-l-1];
							ans[j-l-1] = aux;
							mark[j-l-1] = true;
							l++;
							restante--;
						}					
				}
			}
		}
		for(int i=1;i<=n;++i)
			cout<<ans[i]<<" ";
		cout<<"\n";
	}
}