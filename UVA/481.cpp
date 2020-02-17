#include <bits/stdc++.h>	//O(N*Log(N))
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
const int N = 100010;

int x;
vector<int> v;

int lis(vector<int> &v)
{

	vector<int> pilha,ans;
	int pos[N],pai[N];

	for(int i = 0;i<v.size();++i)		
	{
		auto x = lower_bound(all(pilha),v[i]);
		int p = x - pilha.begin();

		if(x == pilha.end())
			pilha.pb(v[i]);

		else 
			*x = v[i];
		
		pos[p] = i;
		if(p == 0) pai[i] = -1;
		else pai[i] = pos[p-1];
	}

	cout<<pilha.size()<<"\n-\n";

	if(pilha.size() > 0)
	{
		int p = pos[pilha.size() - 1];	
		while(p >= 0)
		{
			ans.pb(v[p]);
			p = pai[p];
		}
		reverse(all(ans));
		for(auto e : ans)
			cout<<e<<"\n";
	}

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(cin>>x)
		v.pb(x);
	lis(v);
}