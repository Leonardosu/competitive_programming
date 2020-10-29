#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 300009 
#define MOD 998244353
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
ll mult(ll a,ll b){
    return a*b%MOD;
}
ll fastpow(ll a, ll b){
    ll calc=1;
    for(;b>=1LL;b/=2LL){
        if((b&1LL))calc=mult(calc,a);
        a=mult(a,a);
    }
    return calc;
}
ll soma(ll a,ll b){
    if(a+b>=MOD)return a+b-MOD;
    else return a+b;
}
ll subt(ll a,ll b){
    if(a-b<0)return a-b+MOD;
    else return a-b;
}
ll fact[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    fact[0]=1;
    rep(i,1,maxn){
        fact[i] = mult(fact[i-1],i);
    }
    ll n,k;
    cin>>n>>k;
    vector<pii> events;
    ll cont=0;
    rep(i,0,n){
        ll a,b;
        cin>>a>>b;
        events.push_back({a,0});
        events.push_back({b,1});
    }
    sort(all(events));
    ll ans=0;
    rep(i,0,sz(events)){
        if(events[i].S==1)cont--;
        else{
            if(cont>=k-1){
                // cout<<"oi\n";
                ans = soma(ans,mult(fact[cont],fastpow(mult(fact[k-1],fact[cont-k+1]),MOD-2)));
            }
            cont++;
        }
        // cout<<cont<<"\n";
    }
    cout<<ans<<"\n";
    return 0;  
}   