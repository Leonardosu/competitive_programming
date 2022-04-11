#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 7;
int pai[N],lv[N];
void reset(int n){for(int i=0;i<n;++i)pai[i]=i,lv[i]=0;}
int find(int x)
{
	if(pai[x] == x) return x;
	return pai[x] = find(pai[x]);
}
void join(int x,int y)
{
	x=find(x),y=find(y);if(x==y) return;
	if(lv[x]>lv[y]) swap(x,y);
	if(lv[x]==lv[y]) lv[x]++;
	pai[y]=x;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, m; 
    cin >> n >> m;

    int ans[n+1];
    reset(n+1);
    for(int i=1;i<=n;++i)
    	cin>>ans[i];
    

    for(int i=0;i<m;++i)
    {
    	int a,b;
    	cin>>a>>b;
    	join(a,b);
    }
    
    for(int i=1;i<=n;++i)
    {
    	if(ans[i] == i)
    		continue;

    	int target = abs(ans[i]);
    	if(find(target) == find(i))
    	{
    		ans[i] *= -1;
    	}
    }

    int qnt = 0;
    for (int i = 1; i <= n; i++) 
    {
    	// cout<<find(i)<<" #";
        if (ans[i] < 0 || ans[i] == i) 
            qnt++;        
    }
    
    cout<<qnt<<"\n";
}