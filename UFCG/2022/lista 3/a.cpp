#include "bits/stdc++.h" // Book of Evil
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
bool haunt[N];
int dp[N];
vi a[N];
 
void DFS(int u, int parent)
{
  dp[u] = (haunt[u] ? 0 : -1);
  for(auto &v : a[u])  
    if (v != parent)
    {
      DFS(v, u);
      dp[u] = max(dp[u], dp[v] < 0 ? dp[v] : dp[v] + 1);
    }  
}
 
int ans, D;
void DFS2(int u, int parent, int other)
{
  if(max(other, dp[u]) <= D)
    ++ans;  

  int x = other, y = -1;
  for(auto &v : a[u])
  {
    if (v != parent)
    {
      int z = dp[v] < 0 ? dp[v] : dp[v] + 1;
      if (z > x) 
      {
        y = x;
        x = z;
      }
      else if (z > y) 
        y = z;  
    }    
  }

  for(auto &v : a[u])
  {
    if (v != parent)
    {
      int new_other = other < 0 ? other : other + 1;
      if (haunt[v]) new_other = max(new_other, 0);
      int z = dp[v] < 0 ? dp[v] : dp[v] + 1;

      if (z != x) 
        new_other = max(new_other, x < 0 ? x : x + 1);
      else
        new_other = max(new_other, y < 0 ? y : y + 1);

      DFS2(v, u, new_other);  
    }  
  }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin>>n>>m>>D;
    for(int i=0,j;i<m;++i)
    {
      cin>>j;
      haunt[j-1] = true;
    }

    int x, y;
    for(int i=1;i<n;++i)
    {
      cin>>x>>y;
      --x; --y;
      a[x].push_back(y);
      a[y].push_back(x);
    }

    DFS(0, -1);
    ans = 0;
    DFS2(0, -1, haunt[0] ? 0 : -1);
    cout<<ans<<"\n";
    return 0;
}
