#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
 
const int N = 1;
const int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;
 
vector<ii> A,B;
int t,n,a,b;
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)
	{
		A.clear(); B.clear();
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>a>>b;
			A.pb(mp(a,b));
			// B.pb(mp(b,a));
		}
 
		sort(all(A));
		string ans = "";
		bool possible = true;
		int maior = 0;
		for(int i=0;i<A.size();++i)
		{
			if(maior > A[i].s)
				{
					possible = false;
					break;
				}
			maior = max(maior,A[i].s);
		}
 
		if(n == 1 && possible)
		{
			for(int i=0;i<A[0].f;++i)
				ans+="R";
			for(int i=0;i<A[0].s;++i)
				ans+="U";
		}
		else if(possible && n > 1)
		{
			for(int i=0;i<A[0].f;++i)
				ans+="R";
			for(int i=0;i<A[0].s;++i)
				ans+="U";
			
			for(int i=1;i<A.size();++i)
			{
				int dif1 = A[i].f - A[i-1].f;
				int dif2 = A[i].s - A[i-1].s;
				for(int i=0;i<dif1;++i)
					ans+="R";
				for(int i=0;i<dif2;++i)
					ans+="U";
			}
		}
 
		if(possible) cout<<"YES\n"<<ans<<"\n";
		else cout<<"NO\n";
	}
 
}