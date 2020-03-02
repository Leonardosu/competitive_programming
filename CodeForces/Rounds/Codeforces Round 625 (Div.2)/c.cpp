#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
const int N = 120;
const int INF = 1e9;
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int t;
int n;
int ans = 0;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
	cin>>n>>s;
	v.resize(n+1);
	int l[N];
	int r[N];
	for(int i=1;i<=n;++i)
		l[i] = i-1,r[i] = i + 1;

	for(int i=0;i<n;++i)
	{
		int x = s[i] - 'a' + 1;
		v[i+1] = x;
	}

	bool flag = true;
	while(flag)
	{
		flag = false;
		for(int i=1;i<=n;++i)
		{
			int maior = -1;
			int pos = -1;

			for(int j=1;j<=n;++j)
			{
				if(v[j] == 1) continue;
				if( ( v[l[j]] + 1 == v[j] || v[r[j]] + 1 == v[j]) && v[j] >= maior) 
					maior = v[j],pos = j;
			}

			if(pos == -1 || v[pos] == -1) break;

			int j = pos;
			int aux = j;
			if(v[j] == v[l[j]] + 1)
			{
				ans++;
				v[j] = -1;	
				flag = true;
			}
			else if(v[j] == v[r[j]] + 1)
			{
				ans++;
				v[j] = -1;
				flag = true;
			}

			if(flag)
			{
				int j = aux;
				int ini = 0;
				int fim = 0;
			
				for(int i=aux;i<=n;++i)
				{
					if(v[i] != -1) 
					{
						fim = i;
						break;
					}
				}

				for(int i=aux;i>=1;i--)
				{
					if(v[i] != -1)
					{
						ini = i;
						break;
					}
				}

				for(int i=ini+1;i<=fim-1;++i)
					l[i] = ini,r[i] = fim;
				
				r[ini] = fim;
				l[fim] = ini;
				break;
			}
		}

	}

	cout<<ans<<"\n";
}