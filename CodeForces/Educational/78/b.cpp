#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"###\n"<<x<<"\n###\n";
using namespace std;

const int N = 44726;
const int INF = 1e9;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int t;
ll a,b;
ll moves,prefix[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	prefix[0] = 0;
	prefix[1] = 1;
	for(int i=2;i<N;++i)
		prefix[i] = prefix[i-1] + i;

	cin>>t;
	while(t--)
	{
		cin>>a>>b; moves = 0;
		if(a < b) swap(a,b);
		ll dif = a - b;

		for(ll i=0;i<N;++i)
		{
			ll soma = (a + b + (i*(i+1LL))/2);
			if(soma%2 == 1) continue;

			ll z = (i*(i+1LL))/2;
			ll s2 = (z + dif), s1 = z - dif;

			if(s2%2 == 1LL || s1%2 == 1LL || s1 < 0LL || s2 < 0LL) continue;
			s2/=2; s1/=2;

			if(a + s1 == b + s2)
			{
				cout<<i<<"\n";
				break;
			}
		}
			
	}
	
}