#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}


int v[1034],m[1034];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int casos;
	cin>>casos;

	while(casos--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;++i) cin>>v[i];
		sort(v+1,v+n+1);

		int k = -1;

		for(int j = 1;j<=1024;++j)
		{

			for(int i=1;i<=n;++i)
				m[i] = (v[i]^j);

			sort(m+1,m+1+n);

			bool ok = true;
			for(int i=1;i<=n;++i)
				if(m[i] != v[i])
				{
					ok = false;
					break;
				}

			if(!ok) continue;
			else
			{
				k = j;
				break;
			}
		}

		cout<<k<<'\n';
	}


}