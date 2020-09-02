#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int qnt[30];
		memset(qnt,0,sizeof(qnt));
		for(int i=0;i<n;++i)
		{
			string s;
			cin>>s;
			for( char c : s)
				qnt[c-'a']++;			
		}

		bool ok = true;
		for(int i=0;i<26;++i)
		{
			if(qnt[i]%n != 0)
				ok = false;
		}
		if(ok) cout<<"YES\n";
		else cout<<"NO\n";
	}
		
}