#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define debug(a) cout<<a<<'\n'
#define maxn 300009 /// I wanna be the wind
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
ll n;
ll dp[maxn][2];
ll vet[maxn+2];
ll solve(ll id, ll sit){
    if(id>=n)return 0;
    if(dp[id][sit]!=-INF)return dp[id][sit];
    if(sit==1)return dp[id][sit] = max(solve(id+1,0)-vet[id],solve(id+1,1));
    else{
        return dp[id][sit] = max(solve(id+1,1)+vet[id],solve(id+1,0));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll q;
        cin>>n>>q;
        rep(i,0,n){
            cin>>vet[i];
        }
        rep(i,0,n+3){
            rep(j,0,2){
                dp[i][j]=-INF;
            }
        }
        cout<<solve(0,0)<<"\n";
    }
    return 0;  
}   