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
const int N = 1e5 + 7;

int road[N][2], leader[N];
ll sz[N], ans[N];

int find(int x){return leader[x]==x?x:leader[x]=find(leader[x]);}
void merge(int a,int b)
{
    a=find(a),b=find(b);
    leader[a]=b;
    sz[b]+=sz[a];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        leader[i]=i,sz[i]=1; 
    for(int i=1;i<=m;i++)
        cin>>road[i][0]>>road[i][1];
    
    ans[m]=n*(n-1)/2;
    for(int i=m-1;i>=1;i--)
    {
        if(find(road[i+1][0])==find(road[i+1][1]))ans[i]=ans[i+1];
        else 
        {   
            ans[i]=ans[i+1]-sz[find(road[i+1][1])]*sz[find(road[i+1][0])];
            merge(road[i+1][0],road[i+1][1]);
            
        }
        if(ans[i]==0)break;
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
}