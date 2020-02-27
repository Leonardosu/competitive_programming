#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;

typedef pair<int,int> ii;
typedef long long int ll;

string color;
vector<ii> v;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	string entrada;
	cin>>entrada;
	for(int i=0;i<n;++i)
	{
		int x = entrada[i] - 'a';
		v.pb({x,i});
	}
	
	for(int i=0;i<n;++i)
		color+='x';

	bool possible = true;

	while(1)
	{
		bool change = false;
		for(int i=0;i<n-1;++i)
		{
			if(v[i].f > v[i+1].f)
			{
				change = true;

				int a = v[i].s;
				int b = v[i+1].s;

				if(color[a] == 'x' && color[b] == 'x')
					color[a] = '0',color[b] = '1';

				else if(color[a] != 'x')
				{
					if(color[b] == 'x')
						color[b] = char( (int(color[a]-'0') + 1)%2 + '0');
					else if(color[a] == color[b])
					{
						change = false;
						possible = false;
						break;
					}
				}
				else
				{	
					if(color[a] == 'x')
						color[a] = char( (int(color[b]-'0') + 1)%2 + '0');					
					else if(color[a] == color[b])
					{
						change = false;
						possible = false;
						break;
					}
				}

				swap(v[i],v[i+1]);
				break;		
			}
		}

		if(!change) break;
	}

	for(int i=0;i<n-1;++i)
	{
		if(v[i].f > v[i+1].f)
		{
			possible = false;
			break;
		}		
	}
	for(int i=0;i<n;++i)
		if(color[i] == 'x')
			color[i] = '0';

	if(possible)
		{
			cout<<"YES\n";
			cout<<color<<"\n";
		}
	else cout<<"NO\n";
}