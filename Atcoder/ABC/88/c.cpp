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
    int grid[4][4];
    

    vector<int> a(4);

    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            cin>>grid[i][j];
    /*
            3a1 + b1+b2+b3

            a2 - a1 = c(2,1) - c(1,1)

            |a1 + b1| |a1 + b2| |a1 + b3|
            |a2 + b1| |a2 + b2| |a2 + b3|
            |a3 + b1| |a3 + b2| |a3 + b3|           
    */
    bool valid = true;
    int K = grid[2][1] - grid[1][1];
    if( K != grid[2][2] - grid[1][2] || K != grid[2][3] - grid[1][3])
        valid = false;

    K = grid[3][1] - grid[2][1];
    if( K != grid[3][2] - grid[2][2] || K != grid[3][3] - grid[2][3])
        valid = false;
    // ----------------------------------
    // ----------------------------------
    K = grid[1][2] - grid[1][1];
    if( K != grid[2][2] - grid[2][1] || K != grid[3][2] - grid[3][1])
        valid = false;

    K = grid[1][3] - grid[1][2];
    if( K != grid[2][3] - grid[2][2] || K != grid[3][3] - grid[3][2])
        valid = false;    
    cout<<(valid ? "Yes" : "No")<<"\n";
}