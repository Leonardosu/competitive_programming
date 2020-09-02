#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 1e5 + 7;
const int inf = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

string p;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	for(int i=0;i<50;++i)
		p += 'a';

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<p<<"\n";
		while(n--)
		{
			int x;
			cin>>x;
			int novo = p[x] - 'a';
			novo = !novo;
			p[x] = 'a' + novo;
			cout<<p<<"\n";
		}

	}

	cout<<"\n";
}