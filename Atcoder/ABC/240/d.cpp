#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vector<int> balls, qnt;

	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;

		if(balls.empty() || balls.back() != x)
		{
			balls.pb(x);
			qnt.pb(1);
		}
		else if(balls.back() == x)
		{
			balls.pb(x);
			qnt.pb(qnt.back() + 1);

			if(qnt.back() == x)
			{
				while(!balls.empty() && balls.back() == x)
				{
					balls.pop_back();
					qnt.pop_back();
				}
			}
				
		}
		else
			cout<<"fudeu\n";
		
		cout<<balls.size()<<"\n";
	}
}