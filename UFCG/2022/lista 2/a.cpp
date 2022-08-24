#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())

#define inf 0x3f3f3f3f
using namespace std;
int f[1001][1001][2],n,x,k;
char g[1001][1001][2];
void dire(int x,int y)
{
    if(x==1 && y==1)
        return;
    if(g[x][y][k])
        dire(x-1,y),printf("D");
    else
        dire(x,y-1),printf("R");
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    for(int i=2; i<=n; ++i)
        f[0][i][0] = f[0][i][1] = f[i][0][0] = f[i][0][1]=inf;

    for(int i=1; i<=n; ++i)  {
        for(int j=1; j<=n; ++j) {
            scanf("%d",&k);
            if(!k) 
            	x=i;
            else {
                while(k%2==0)
                    ++f[i][j][0],k/=2;
                while(k%5==0)
                    ++f[i][j][1],k/=5;
            }
            for(int k=0; k<2; k++)
            {
                if(g[i][j][k] = f[i-1][j][k]<f[i][j-1][k])
                    f[i][j][k]+=f[i-1][j][k];
                else
                    f[i][j][k]+=f[i][j-1][k];
            }
        }
    }
    k=f[n][n][1]<f[n][n][0];
    if(x && f[n][n][k]>1) {
        cout<<"1\n"; 
        for(int i=2; i<=x; i++)
        	cout<<"D";
            printf("D");
        for(int i=2; i<=n; i++)
            cout<<"R";
        for(int i=x+1; i<=n; i++)
            cout<<"D";
    } else {
    	cout<<f[n][n][k]<<"\n";
    	dire(n, n);
    }
    return 0;
}