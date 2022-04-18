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

    int n;
    cin>>n;

    int lv[n+1];
    memset(lv, 0,sizeof(lv));
    for(int i=1;i<n;++i)
    {
    	int x,y;
    	cin>>x>>y;
    	lv[x]++;
    	lv[y]++;
    }

    int qnt = 0;
    bool star = false;
    for(int i=1;i<=n;++i)
    {
    	if(lv[i]) 
    		qnt++;
    	if(lv[i] == n-1)
    		star = true;
    }

    if(qnt == n && star)
    	cout<<"Yes\n";
    else
    	cout<<"No\n";
}