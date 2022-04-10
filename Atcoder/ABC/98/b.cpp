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
	string s;
	int n;
	cin>>n;
	
	cin>>s;
	int ans = 0;
	for(int i=0;i<sz(s)-1;++i)
	{
		bool a[26],b[26];
		memset(a,false,sizeof(a));
		memset(b,false,sizeof(b));

		for(int k=0;k<=i;++k)
			a[s[k]-'a'] = true;

		for(int k=i+1;k<sz(s);++k)
			b[s[k]-'a'] = true;

		int qnt = 0;
		for(int i=0;i<26;++i)
			if(a[i] && b[i])
				qnt++;
		ans = max(ans,qnt);
	}
	cout<<ans<<"\n";
}