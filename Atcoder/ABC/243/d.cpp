#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, pos;
    string op;
    cin>>n>>pos>>op;

    stack<char> ops;
    string sss = "";

    for(char &c : op)
    {
    	if(c == 'U' && !ops.empty())
    		ops.pop();
    	else if(c == 'L')
    		ops.push('L');
    	else if(c == 'R')
    		ops.push('R');
    	else
    		pos>>=(1LL);
    }

    while(!ops.empty())
    {
    	sss += ops.top(); 
    	ops.pop();
    }

    reverse(ALL(sss));
    // cout<<sss<<"\n";
    for(char &c : sss)
    {
    	if(c == 'U')
    		pos>>=1LL;
    	else if(c == 'L')
    		pos<<=1LL;
    	else
    		pos<<=1LL, pos++;
    }
    cout<<pos<<"\n";
}