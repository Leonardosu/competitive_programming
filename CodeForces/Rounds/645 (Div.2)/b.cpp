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


int n,ans;
vector<int> caras;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;

	cin>>t;
	while(t--)
	{
		cin>>n;
		ans = 0;
		caras.resize(n);
		for(int i=0;i<n;++i)
			cin>>caras[i];

		sort(all(caras));
		int now = 1;
		for(int i=0;i<n;++i)
		{
			if(caras[i] <= now)
				now++;			
			else
			{
				int plus = 1;
				bool pick = false;
				for(int j=i+1;j<n;++j)
				{
					if(caras[j] <= now + plus)
					{
						now += (plus+1);
						i = j;
						pick = true;
						break;
					}
					else
						plus++;
				}

				if(!pick) break;
			}
		}
		cout<<now<<'\n';
	}


}