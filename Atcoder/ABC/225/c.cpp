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
typedef vector<ll> vi;

bool valid(vector<vi> mat)
{
	int n = mat.size(), m = mat[0].size();
	for(ll i=0;i<n;++i)
	{
		for(ll j=0;j<m;++j)
		{
			if(j && (mat[i][j-1] + 1LL != mat[i][j]))
				return false;
		
			if(i && (mat[i-1][j] + 7 != mat[i][j]))
				return false;
			
		}		
	}
	
	for(int j=1;j<m;++j)
		if(mat[0][j]%7 == 0)
			return false;
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    vector<vi> v(n, vi(m));
    for(int i=0;i<n;++i)
    	for(int j=0;j<m;++j)
    	{
    		cin>>v[i][j];
    		v[i][j]--;
    	}

    if(valid(v))
    	cout<<"Yes";
    else
    	cout<<"No";
    cout<<"\n";
}