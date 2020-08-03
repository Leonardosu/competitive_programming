#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"### _("<<x<<")_###\n";
using namespace std;

const int N = 1e5;
const int INF = 1e9;
typedef long long int ll;
typedef pair<int,int> ii;

int v[4*N + 100];
int t,n,g,s,b;
vector<int> ini;
bool possible;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n;

		for(int i=1;i<=n;++i)
			cin>>v[i];
		v[n+1] = -123321;

		g = s = b = 0; possible = true;
		int last = v[1],pos = 1;
		
		while(v[pos] == last)
			g++,pos++;		
		
		int cnt = 0;
		while(s <= g)
		{
			last = v[pos];
			while(pos<=n && v[pos] == last)
				s++,pos++;
			if(pos > n) break;
		}

		while(b <= g)
		{
			last = v[pos];
			while(pos<=n && v[pos] == last)
				b++,pos++;
			if(pos > n) break;
		}

		while(pos <= n/2)
		{
			cnt = 0;
			last = v[pos];
			while(pos<=n && v[pos] == last)
				cnt++,pos++;

			if(pos-1 <= n/2)
				b+=cnt;			
			else		
				break;					
		}

		if(g >= s || g>= b || s == 0 || g == 0 || g+s+b > n/2) 
			cout<<"0 0 0\n";
		else
			cout<<g<<" "<<s<<" "<<b<<"\n";
	}
}