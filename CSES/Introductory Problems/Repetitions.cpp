#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>s;
	int now = 0,best = 0;
	char atual = s[0];

	for(int i=0;i<s.size();++i)
	{
		if(s[i] == atual)
			now++;
		else
		{
			best = max(best,now);
			now = 1;
			atual = s[i];
		}		
	}
	
	best = max(best,now);
	cout<<best<<'\n';
}