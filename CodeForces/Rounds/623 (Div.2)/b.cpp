#include <bits/stdc++.h>
#define f first
// #define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

int t;
ll a,b,p,ans,now;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		string s;

		cin>>a>>b>>p;
		cin>>s;

		s = "!" + s;

		n = s.size();
		now = 0LL;
		ans = n - 1;

		for(int i=n-2;i>0;--i)
		{
			if(s[i] != s[i-1])
			{
				now += (s[i] == 'A') ? a : b;
				if(now <= p)
					ans = i;
			}
		}
			
		cout<<ans<<'\n';
	}	
}