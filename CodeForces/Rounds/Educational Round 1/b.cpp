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

    string s;
    cin>>s;

    int q;
    cin>>q;

    while(q--)
    {
    	int l,r,k;
    	cin>>l>>r>>k;
    	l--,r--;

    	int len = r - l + 1;
    	k %= len;
    	string temp = s;
    	int next = r - k + 1;
    	for(int i=l;i<=r;++i)
    	{
    		if(next > r)
    			next = l + (next - r - 1);
    		s[i] = (temp[next]);
    		next++;
    	}
    }
    cout<<s<<"\n";
}