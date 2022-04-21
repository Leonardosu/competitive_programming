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

    int a,b,k;
    cin>>a>>b>>k;

    set<int> ans;
    for(int i=a;i<=min(a+k-1,b);++i)
    {
    	ans.insert(i);
    }
    for(int i=b;i>=max(a,b-k+1);--i)
    {
    	ans.insert(i);
    }

    for(auto &x : ans)
    	cout<<x<<"\n";
}