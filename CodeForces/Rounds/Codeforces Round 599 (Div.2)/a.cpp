#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define vi vector<int> v;
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
const int N = 100000;
const int INF = 1e9;
const int MOD = 1e9 + 7;
 
vi;
int t;
int n,x,best;
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();
 
		for(int i=0;i<n;++i)
		{
			cin>>x;
			v.pb(x);
		}
 
		sort(all(v));
		best  = 0;
 
		for(int i=0;i<n;++i)
		{
			int atual = v[i];			
			best = max(best,min(atual,n-i));
		}
		cout<<best<<"\n";
	}
 
}