#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int maxn = 1;
const int inf = 1;
const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    string a,b,c;
    int cnt = 0;
    cin>>a>>b>>c;
    if(a == "bubble" || a == "tapioka")
        a = "",cnt++;
    if(b == "bubble" || b == "tapioka")
        b = "",cnt++;
    if(c == "bubble" || c == "tapioka")
       c = "",cnt++;
    if(cnt < 3)
    {
        if(a != "") cout<<a<<" ";
        if(b != "") cout<<b<<" ";
        if(c != "") cout<<c<<"";
        cout<<"\n";
    }
    else
    {
        cout<<"nothing\n";
    }
    
}
