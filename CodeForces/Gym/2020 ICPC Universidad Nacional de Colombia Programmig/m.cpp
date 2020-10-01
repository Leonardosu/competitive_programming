#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 4e5 + 7;

int n, id;

vector<int> g[26];
int prox[26][maxn];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s;
    int q;
    memset(prox,-1,sizeof(prox));

    cin>>s;
    cin>>q;
    
    int n = s.size();

    for(int i=0;i<n;++i)
    {
        int c = s[i] - 'a';
        int j = i;

        while(j >= 0 && prox[c][j] == -1)
        {
            if(prox[c][j] != -1) break;
            prox[c][j] = i;
            j--;
        }
    }
        
    
    while(q--)
    {
        string ss;
        cin>>ss;
        string ans = "";

        int j = 0;

        for(int i=0;i<ss.size();++i)
        {
            int c = ss[i] - 'a';
            j = prox[c][j];
            if(j == -1) break;
            j++;
            ans.pb(ss[i]);
        }

        if(ans == "") ans = "IMPOSSIBLE";
        cout<<ans<<"\n";
    }
}