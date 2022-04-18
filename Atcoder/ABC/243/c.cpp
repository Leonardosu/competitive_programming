#include "bits/stdc++.h"
#define pos first
#define id second
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

    int n;
    string s;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;++i)
    	cin>>v[i].first>>v[i].second;

    cin>>s;

    map<int, vector<pair<int,int>>> caras;
    for(int i=0;i<n;++i)
    {
    	auto &[x,y] = v[i];
    	int dir = (s[i] == 'L' ? -1 : 1);

    	caras[y].pb({x, dir});
    }

    bool can = false;
    for(auto &[y, peo] : caras)
    {
    	sort(ALL(peo));
    	bool direita = false;
    	for(auto &[x, dir] : peo)
    	{
    		if(dir == -1 && direita)
    		{
    			can = true;
    			break;
    		}
    		if(dir == 1)
    			direita = true;
    	}
    	if(can)
    		break;
    }

    cout<<(can ? "Yes" : "No")<<"\n";
}