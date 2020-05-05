#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> par,impar,ans;
int n;
bool ok = true;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		if(i%2) impar.pb(i);
		else par.pb(i);
	}

	sort(par.begin(),par.end());
	sort(impar.begin(),impar.end());
	for(int i=0;i<par.size();++i) ans.pb(par[i]);
	for(int i=0;i<impar.size();++i) ans.pb(impar[i]);

	for(int i=1;i<n;++i)
		if(abs(ans[i] - ans[i-1]) == 1)
		{
			ok = false;
			break;
		}
	if(ok)
		for(int x : ans) cout<<x<<" ";
	else
		cout<<"NO SOLUTION\n";
}
