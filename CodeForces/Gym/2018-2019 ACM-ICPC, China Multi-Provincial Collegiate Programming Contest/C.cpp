#include <bits/stdc++.h> //Ad-Hoc
#define pb push_back
#define mp make_pair
 using namespace std;
 
string p,s;
int t,x,n,m;
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
	cin>>t;
	for(int z = 1;z<=t;++z)
	{
		cin>>n>>m;
		cin>>p>>s;
		int x = (p[0]-'A') - (s[0]-'A');
 
		cin>>s;
		x += 26;
		x = x%26;
 
		for(int i=0;i<s.size();++i)
		{
			int y = s[i] - 'A';
			y+=x;
			y = (y)%26;
			s[i] = y + 'A';
		}
		cout<<"Case #"<<z<<": "<<s<<"\n";
	}
}