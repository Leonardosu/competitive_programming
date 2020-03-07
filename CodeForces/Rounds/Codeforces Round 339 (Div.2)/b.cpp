#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll prod;
int n;
string ans;
bool zero = false;

bool beaut(string x)
{
	if(x[0] != '1') return false;
	for(int i=1;i<x.size();++i)
		if(x[i] != '0') return false;

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	string prod = "1",x;
	ll cnt = 0LL;

	while(n--)
	{

		cin>>x;
		if(beaut(x))
			cnt += x.size() - 1;		
		else
		{
			if(x[0] == '0') zero = true;
			else prod = x;
		}
		
	}

	string s = "";
	for(ll i=0LL;i<cnt;++i) s+='0';
	if(zero) cout<<"0\n";
	else	cout<<prod<<s<<'\n';
}
