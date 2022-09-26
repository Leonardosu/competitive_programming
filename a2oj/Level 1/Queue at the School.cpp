#include <bits/stdc++.h>
using namespace std;

string s;
int n,t;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>n>>t;
    cin>>s;
    while(t--)
    {
        for(int i=0;i<n-1;++i)
        {
            if(s[i] == 'B' && s[i+1] == 'G')
                swap(s[i],s[i+1]),i++;
        }
    }
    cout<<s<<"\n";
}