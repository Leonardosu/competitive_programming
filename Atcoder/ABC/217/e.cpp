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

/*
    4, 3, 2, 1
*/

struct magic {
    queue<int> caras;
    priority_queue<int, vi, greater<int>> toAdd;
    int cnt = 0;

    bool sorted = false;

    void sort() {
        while(!caras.empty()) {
            toAdd.push(caras.front());
            caras.pop();
        }
        cnt = toAdd.size();
    }

    void append(int x) {
        caras.push(x);
    }

    int get() {
        if(cnt) {
            int x = toAdd.top();
            toAdd.pop();
            cnt--;
            return x;
        } else {
            int x = caras.front();
            caras.pop();
            return x;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin>>q;
    magic data;

    while(q--) {
        int t;
        cin>>t;

        if(t == 1) {
            int x;
            cin>>x;
            data.append(x);
        } else if(t == 2) {
            cout<<data.get()<<"\n";
        } else {
            data.sort();
        }
    }    
}