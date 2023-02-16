#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int x;
    cin>>x;

    bool ok=false;
    for(int i=1;i<x;++i) {
        if(i%2==0 && (x-i)%2==0) {
            ok = true; 
            break;
        }
    }

    cout<<(ok ? "YES" : "NO")<<"\n";
    return 0;
}
