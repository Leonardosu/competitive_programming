#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string mark,s;
set<string> ans;
int n;

void go(string now,string mark)
{
	if(now.size() == s.size())
	{
		ans.insert(now);
		return;
	}

	for(int i=0;i<n;++i)
		if(mark[i] == '0')
		{
			mark[i] = '1';
			go(now+s[i],mark);
			mark[i] = '0';
		}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>s;	
	n = s.size();
	string aux = "",start = "";
	for(int i=0;i<n;++i) aux+='0';
	go(start,aux);
	
	cout<<ans.size()<<"\n";
	for(auto x : ans) cout<<x<<"\n";
}