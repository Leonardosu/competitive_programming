#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long int ll;
int n,t;
ll moves,sum;
string now;
vector<int> zeros;
// 9428683473

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n>>moves;
		cin>>now;

		zeros.clear();
		for(int i=0;i<now.size();++i)
			if(now[i] == '0')
				zeros.pb(i);

		int pos = 0;
		sum = 0;
		for(int i=0;i<zeros.size();++i)
		{
			sum+=(zeros[i] - i);			
		}

		if(moves >= sum)
		{
			for(int i=0;i<now.size();++i)
				now[i] = '1';

			for(int i=0;i<zeros.size();++i)
				now[i] = '0';
		}
		else
		{
			for(int i=0;i<zeros.size();++i)
			{
				int x = zeros[i];
				if(moves < x - pos)
				{
					zeros[i]-=moves;
					moves = 0;
					break;
				}
				else
					zeros[i]=pos,moves-=(x-pos),pos++;
			}
			for(int i=0;i<now.size();++i)
				now[i] = '1';

			for(int i=0;i<zeros.size();++i)
				now[zeros[i]] = '0';
		}
		
		cout<<now<<"\n";
	}
}