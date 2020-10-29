#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 200009
#define MOD 1000000007
#define F first
#define S second
#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define per(i, b, a) for(ll i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
using namespace std;
const ll INF = 1e14 + 9;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll vet[n+2];
        ll can=false;
        rep(i,0,n){
            cin>>vet[i];
        } 
        rep(i,0,n-1){
            if(vet[i]<=vet[i+1])can=true;
        }
        if(can)cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;  
}   