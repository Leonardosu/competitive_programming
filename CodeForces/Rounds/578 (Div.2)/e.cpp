#include <bits/stdc++.h> // Compress Words
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 11000020;

int f[maxn];
string ans,s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {   
        cin>>s;
        string sufixo = "";
        for(int j = ans.size() - 1,i = 0; i < s.size() + 2 && j >= 0; --j,++i)
            sufixo.pb(ans[j]);
        reverse(all(s));
        sufixo.pb('$');
        sufixo += s;

        f[0] = -1;
        for(int i=0,j=-1;i<(int)sufixo.size();++i)
        {
            while(j >= 0 && sufixo[i] != sufixo[j]) j = f[j];
            j++;
            f[i+1] = j;
        }

        int ini = min(int(s.size()),int(f[sufixo.size()]));
        reverse(all(s));

        for(int i = ini;i<s.size();++i)
            ans.pb(s[i]);        
    }
    cout<<ans<<"\n";
}