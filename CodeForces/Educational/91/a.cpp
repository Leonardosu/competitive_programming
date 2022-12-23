#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 1010;

int v[maxn];
struct T
{
	int val;
	int id;
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>v[i];

		bool up = false,down = false;
		int a = -1,b = 0,c = 1;
		for(int i=2;i<=n;++i)
		{
			if(v[i-1] < v[i])
			{
				up = true;
				a = i-1;
				b = i;
			}
			if(v[i-1] > v[i] && up)
			{
				down = true;
				c = i;
				break;
			}
		}

		if(up && down)
		{
			cout<<"YES\n";
			cout<<a<<" "<<b<<" "<<c<<"\n";
		}
		else
			cout<<"NO\n";
	}
		
}