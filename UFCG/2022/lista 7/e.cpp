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

    int v[n]; memset(v, 0, sizeof v);
    char a[n+1], b[n+1];

    for(int i=1;i<=n;++i)
    	cin>>a[i];
    for(int i=1;i<=n;++i) {
    	cin>>b[i];
    	v[i] = a[i] + b[i] - 'a' - 'a';
    }


    for(int i=n;i>=2;--i){
    	v[i-1] += v[i]/26;
    	v[i]%=26;
    }

    for(int i=1;i<=n;++i) {
    	if(v[i]&1)
    		v[i+1] += 26;
    	cout<<char('a' + v[i]/2);
    }
    cout<<"\n";
}