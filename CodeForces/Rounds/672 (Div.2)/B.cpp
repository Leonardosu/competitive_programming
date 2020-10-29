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
        ll vet2[n+2];
        map<int,int> cont2;
        rep(i,0,n){
            cin>>vet[i];
            ll cont=1;
            while(vet[i]!=0){
                if(vet[i]&1)vet2[i]=cont;
                cont++;
                vet[i]>>=1;
            }
        }
        ll ans=0;
        rep(i,0,n){
            ans+=cont2[vet2[i]];
            cont2[vet2[i]]++;
        }
        cout<<ans<<"\n";
    }
    return 0;  
}   