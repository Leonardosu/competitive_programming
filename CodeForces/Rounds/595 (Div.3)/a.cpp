#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
using namespace std;
 
const int N = 10;
const int INF = 1e8;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
vector<int> v;
int n,q,x;
bool flag;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>q;
	while(q--)
	{
		v.clear();
		flag = false;
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>x;
			v.pb(x);
		}
		sort(all(v));
 
		for(int i=0;i<n-1;++i)
		{
			if(v[i+1] - v[i] == 1)
			{
				flag = true;
				break;
			}
		}
 
		if(flag) cout<<"2\n";
		else cout<<"1\n";
	}
 
}