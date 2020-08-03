#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define N 150010
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
int t,n,ans,x;
vector<int> v;
bool tem_menor[N];
 
void make()
{
	stack<ii> pilha;
 
	pilha.push(mp(v[0],0));
 
	for(int i=1;i<v.size();++i)
	{
		int x = v[i];
 
		while(!pilha.empty() && pilha.top().f > x)
		{
			ii y = pilha.top(); pilha.pop();
 
			tem_menor[y.s] = true;
		}
 
		pilha.push(mp(x,i));
	}
 
}
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
 
	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();	ans = 0;
 
		for(int i=0;i<n;++i)
		{
			cin>>x;
			v.pb(x);
			tem_menor[i] = false;
		}
 
		make();
 
		for(int i=0;i<n;++i)
			if(tem_menor[i])
				ans++;
			
 
		cout<<ans<<"\n";
	}
 
}