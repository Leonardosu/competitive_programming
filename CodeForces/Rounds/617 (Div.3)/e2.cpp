#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int n,maior[32];
string s;
vector<int> ans;

int main()
{

	IOS
	
	cin>>n>>s;
	ans.resize(n);
	int best = 1;

	for(int i=0;i<n;++i)
	{
		int x = s[i] - 'a';

		for(int j=0;j<26;++j)
			if(x >= maior[j])
			{
				maior[j] = max(maior[j],x);
				best = max(best,j + 1),ans[i] = j + 1;
				break;
			}		
	}
	cout<<best<<"\n";
	for(int e : ans) cout<<e<<" ";
		cout<<"\n";
}