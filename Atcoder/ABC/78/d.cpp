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


    int n, x, y;
    cin>>n>>x>>y;

    int v[n+1];
    for(int i=1;i<=n;++i)
    	cin>>v[i];
    if(n == 1) {
    	cout<<abs(v[1] - y);
    } else {
    	cout<<max(abs(y-v[n]), abs(v[n-1]-v[n]));
    }
    cout<<"\n";
}