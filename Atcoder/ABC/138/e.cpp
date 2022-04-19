#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<char, vector<int>> pos;

    string s;
    cin>>s;

    int n = s.size();
    for(int i=0;i<n;++i)
    	pos[s[i]].pb(i);

    cin>>s;

    ll cycle = 0, last = -1;
    for(char &c : s)
    {
    	if(pos.count(c))
    	{
	    	auto idx = lower_bound(ALL(pos[c]), last);
	    	
	    	if(idx == pos[c].end())
	    	{
	    		cycle++;
	    		last = pos[c][0] + 1;
	    	}
	    	else
	    		last = *idx + 1;
    	}
    	else
    	{
    		cout<<"-1\n";
    		return 0;
    	}
    }

	cout<<cycle*n + last<<"\n";
}