#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 1e6 + 7;
const int inf = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

int n;
int a[maxn],b[maxn];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	set<int> caras;
	for(int i=0;i<=100000;++i) caras.insert(i);


	a[0] = a[n+1] = -1;
	int last = 1;
	bool ok = true;

	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i] > i || a[i-1] > a[i]) ok = false;		
		caras.erase(a[i]);
		b[i] = -1;
	}

	for(int i=1;i<=n;++i)
	{
		if(a[i] != a[i+1])
			b[i+1] = a[i];	
				
		if(b[i] == -1)
		{
			b[i] = *caras.begin();
			caras.erase(b[i]);
		}
	}		

	if(!ok) cout<<"-1\n";
	else
	{
		for(int i=1;i<=n;++i)
			cout<<b[i]<<" ";
		cout<<"\n";		
	}
}