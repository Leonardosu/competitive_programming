#include <bits/stdc++.h>
#define f fist
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1e5;
const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long int ll;
typedef pair<int,int> ii;

string now,aux;
string one = "one",two = "two";
int ans;
int t,n;
vector<int> id;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{

		cin>>now;

		ans = 0;
		id.clear();
		n = now.size();
		for(int i=0;i<n - 2;++i)
		{
			aux = now[i];
			aux += now[i + 1];
			aux += now[i + 2];

			if(aux == one)
			{
				now[i + 1] = 'x';
				id.pb(i+1);
				ans++;
			}
			if(aux == two)
			{
				if(i+3 < n && now[i+3] == 'n')
				{
					id.pb(i+2);
					now[i+2] = 'x';
				}
				else
				{
					now[i + 1] = 'x';
					id.pb(i+1);
				}
				ans++;
			}
		}

		cout<<ans<<"\n";

		for(int i = 0;i<id.size();++i)
		{
			cout<<id[i]+1;
			if(i < id.size()) cout<<" ";
		}
		
		if(t)
			cout<<"\n";
	}	

}