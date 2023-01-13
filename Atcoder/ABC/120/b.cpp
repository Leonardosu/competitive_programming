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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, k;
    cin>>a>>b>>k;
    for(int i=min(a,b);i>=1;--i) {
        if(a%i == 0 && b%i == 0) {
            k--;
            if(k == 0) {
                cout<<i<<"\n";
                return 0;
            }
        }
    }
}