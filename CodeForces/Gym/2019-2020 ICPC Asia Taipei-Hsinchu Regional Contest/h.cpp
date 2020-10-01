#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
const int maxn = 1;
const int inf = 1;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin>>t;
    while(t--) 
    {
        ll n;
        cin>>n;
        ll b = n + 1;
        cout<<( ((n*b)/(b-n)) ^ b)<<"\n";
    }
    
}