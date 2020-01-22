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
 
vector<int> v;
int x,n,t;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)
	{
		v.clear();
		for(int i=0;i<3;++i)
		{
			cin>>x;
			v.pb(x);
		}
		cin>>n;
 
		sort(all(v));
		bool possible = true;
		int dif = v[2] - v[0];
		v[0]+= (dif);
		n-=dif;
		dif = v[2] - v[1];
		v[1]+=dif;
		n-=dif;
 
		if(n < 0) possible = false;
		else
		{
			if(n%3 == 0) possible = true;
			else	possible = false;
		}
 
		if(possible) cout<<"YES\n";
		else cout<<"NO\n";
	}
 
}