#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 400010;
const int INF = 1e9;

int t;
string a,b;
vector<int> g[30];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		for(int i=0;i<28;++i)
			g[i].clear();
		
		for(int i=0;i<a.size();++i)
		{
			char x = a[i] - 'a';
			g[x].pb(i);
		}

		int pos = 0;
		int moves = 1;
		int last = 0;
		bool possible = true;

		
		while(pos < b.size())
		{
			int x = b[pos] - 'a';

			if(g[x].empty())
			{
				possible = false;
				break;
			}

			int k = g[x].size();

			if(g[x][k-1] <	last)
			{
				last = g[x][0] + 1;				
				moves++;
				pos++;
				continue;
			}

			int l = 0,r = g[x].size() - 1;
			int mid;
			int aux;
			bool find = false;

			while(l<=r)
			{
				mid = (l+r)/2;
				if(last == g[x][mid])
				{
					last = g[x][mid] + 1;
					pos++;
					find = false;
					break;
				}

				if(last > g[x][mid])
					l = mid + 1;
				else
					r = mid - 1,aux = g[x][mid] + 1,find = true;
			}

			if(find && aux > last) pos++,last = aux;
		}

		if(!possible) moves = -1;
		cout<<moves<<"\n";
	}

}