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
    vector<pair<array<int, 3>,string>> v;

    for(int i=0;i<n;++i) {
    	int a,b,c;
    	string name;
    	cin>>a>>b>>c;
    	
    	getline(cin, name);
    	name = name.substr(1, name.size());
    	v.pb({{-a,-b,-c},name});
    }
    sort(ALL(v));
    cout<<v[0].s<<"\n";
}