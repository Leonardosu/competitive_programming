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

const int N = 1e4 + 7;
int freq[N];
int PQP[N];
int k, n;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    double timing = clock();
    
    cin>>k>>n;

    for(int i=0;i<n;++i) {
        int x;
        cin>>x;
        freq[x]++;
    }


    auto valid = [&]() {
        int qnt = freq[1];
        for(int i=1;i<=k;++i) {
            if(freq[i] != qnt) return false;
        }
        return true;
    };

    for(int i=1;i<=k;++i) { //+A
        freq[i]++;
        if(valid()) {
            cout<<"+"+to_string(i)<<endl;
            return 0;
        }
        freq[i]--;
    }

    for(int i=1;i<=k;++i) { //-A
        freq[i]--;
        if(valid()) {
            cout<<"-"+to_string(i)<<endl;
            return 0;
        }
        freq[i]++;
    }


    for(int i=1;i<=k;++i) {
        PQP[freq[i]]++;
    }

    for(int i=1;i<=k;++i) {
        if(PQP[freq[i]] == 1 && PQP[freq[i]+1] == k-2) {

            for(int j=1;j<=k;++j) {
                if(PQP[freq[j]] == 1 && freq[i] +2 == freq[j]) {
                    cout<<"-"+to_string(j) + " +"+to_string(i)<<endl;
                    return 0;
                }
            }
        }
    }

    cout<<"*"<<endl;
    //--------------------------
    cerr<<"\n\nREAL TIME: "<<fixed<<setprecision(4)<<(clock()-timing)/CLOCKS_PER_SEC<<endl;
}