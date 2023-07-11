#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
mt19937 rng((ll) std::chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6+10;
ll dist[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    ll n;
    cin>>n;

    for(int i=0;i<=n;++i)
    	dist[i]=-1;

    dist[1]=1;
    deque<ll> fila;
    fila.push_back(1);

    while(!fila.empty()) {
    	ll u=fila.front();
    	fila.pop_front();

    	ll x=(u+1)%n, y=(u*10)%n;

    	if(dist[x]==-1) { //cost 1
    		dist[x]=dist[u]+1;
    		fila.push_back(x);
    	}
    	if(dist[y]==-1) { //cost 0
    		dist[y]=dist[u];
    		fila.push_front(y);
    	}
    }

    assert(dist[0] != -1);
    cout<<dist[0]<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}