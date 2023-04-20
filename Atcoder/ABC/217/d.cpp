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


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q;
    cin>>n>>q;

    set<pii> pecas;
    int limit = 1e9 + 12;
    pecas.insert({1, n});
    auto pega = [&](int k) {
        auto it = pecas.upper_bound({k, limit});
        it--;

        if((*it).s >= k)
            return *it;
        it--;
    
        return *it;
    };

    while(q--) {
        int t, x;
        cin>>t>>x;

        if(t == 1) {
            auto mark = pega(x);
            pecas.erase(mark);
            int l = mark.f;
            int r = mark.s;

            pecas.insert({l, x});
            pecas.insert({x+1, r});
        } else {
            auto mark = pega(x);
            cout<<mark.s - mark.f + 1<<"\n";
        }
    }
}