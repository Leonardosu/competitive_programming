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

int n,c0,c1,h;
ll calc_cost(string s) {
    ll res = 0;
    for(char &c : s) {
        if(c == '0')
            res += c0;
        else 
            res += c1;
    }
    return res;
}


void solve_task()
{
    cin>>n>>c0>>c1>>h;
    string s;
    cin>>s;
    

    ll cost = calc_cost(s);
    string tmp = s;
    ll curr = 0;

    for(char &c : tmp) { //all zero
        if (c == '1') {
            c = '0';
            curr += h;
        }
    }
    curr += calc_cost(tmp);

    cost = min(cost, curr);

    tmp = s;
    curr = 0;
    for(char &c : tmp) { //all one
        if (c == '0') {
            c = '1';
            curr += h;
        }
    }
    curr += calc_cost(tmp);

    cost = min(cost, curr);

    cout<<cost<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}