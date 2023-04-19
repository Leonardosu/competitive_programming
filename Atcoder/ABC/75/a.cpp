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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int a, b, c;
    cin>>a>>b>>c;
    if(a == b)
    	cout<<c;
    else if(a == c)
    	cout<<b;
    else cout<<a;
    cout<<"\n";
}