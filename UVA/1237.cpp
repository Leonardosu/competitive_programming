#include <bits/stdc++.h>	// 1237 - Expert Enough? UVA 
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,string> iis;

string name;
vector<iis> input;
int t,n,q;
int a,b;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	for(int z=0;z<t;++z)
	{
		if(z != 0)
			cout<<"\n";

		input.clear();
		cin>>n;
		
		for(int i=0;i<n;++i)
		{
			cin>>name>>a>>b;
			input.pb(mp(mp(a,b),name));
		}

		sort(input.begin(),input.end());

		cin>>q;
		while(q--)
		{
			cin>>a;
			int id = 0,mid;
			int l = 0, r = n-1;
			int front = 0;
			bool find = false;

			while( l <= r )
			{
				mid = (l+r)/2;

				front = input[mid].f.f;

				if(front == a)
				{
					while(mid > 0 && input[mid].f.f == a)
						mid--;

					id = mid;
					break;
				}

				if(front < a)
					r = mid - 1,id = mid;
				else if(a < front)
					l = mid + 1;
			}

			int pos = 0;
			find = false;

			for(int i=id;i<n;++i)
			{
				if(input[i].f.f<=a && a<=input[i].f.s)
				{
					if(find)
					{
						find = false;
						break;
					}

					find = true;
					pos = i;
				}
			}

			if(!find)
				cout<<"UNDETERMINED\n";
			else
				cout<<input[pos].s<<"\n";
		}

	}
}