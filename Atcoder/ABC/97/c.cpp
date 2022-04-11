#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


	// set<string> data;

	set<string> data;
	string s;
	int k;
	cin>>s>>k;
	int n = sz(s);

	// vector<pii> pos;
	map<int,vector<int>> pos;
	for(int i=0;i<n;++i)
		pos[s[i]-'a'].pb(i);
		

	for(int letra=0;letra<26;++letra)
	{
		for(auto &i : pos[letra])
		{
			string curr = "";
			int len = 0;
			while(i < n && len < 6)
			{
				curr += s[i];
				data.insert(curr);		
				i++;
				len++;
			}	
		}
		if(data.size() >= k)
			break;					
	}

	for(auto &ss : data)
	{
		k--;
		if(!k)
		{
			cout<<ss<<"\n";
			return 0;
		}
	}
}