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

void solve_task()
{
	int x, y;
    cin>>x>>y;
    // x = 50;
    // y = 50;
    int res = x*x + y*y;
    int k = sqrt(res);

    if(x + y == 0)
        cout<<0<<"\n";
    else if(k*k == res)
        cout<<1<<"\n";
    else
        cout<<2<<"\n";
    // set<int> caras;
    // for(int i=0;i<=x;++i)
    //     for(int j=0;j<=y;++j)
    //     {
    //         int res = i*i + j*j;
    //         if(sqrt(res)*sqrt(res) == res)
    //         {
    //             cout<<i<<" + "<<j<<" ##\n";
    //             caras.insert(sqrt(res));
    //         }
    //     }

    // for(auto &x : caras)
    //     cout<<x<<"\n";
    // cout<<caras.size()<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}