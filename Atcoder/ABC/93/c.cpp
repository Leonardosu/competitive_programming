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

    int n = 3;
    vi v(n);
    for(int i=0;i<n;++i)
    	cin>>v[i];

    sort(ALL(v));

    int moves = 0;
    int can = (v[1] - v[0])/2;
    moves += can;

    v[1] -= can*2;
    v[2] -= can*2;
    moves += v[1] - v[0];
    moves += v[2] - v[0];
    cout<<moves<<"\n";
}