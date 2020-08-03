#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;

typedef pair<int,int> ii;
typedef long long int ll;

int n,a,b,k;
int pontos;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>a>>b>>k;
	for(int i=0;i<n;++i)
	{
		int h;
		cin>>h;

		if(h <= a)
		{
			pontos++;
			continue;
		}

		h%=(a+b);

		if(h > 0 && h <= a) pontos++;
		else
		{
			int need = 0;	
			if(h == 0) h = a + b;
			h-=a;
			need = (h+a-1)/a;
			
			if(h <= a) need = 1;
			v.pb(need);
		}
	}

	sort(all(v));
	int qnt = 0;

	for(auto e : v)
	{
		k-=e;
		if(k >= 0) qnt++;
		else break;
	}
	cout<<pontos + qnt<<"\n";
}