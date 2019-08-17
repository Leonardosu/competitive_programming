#include <bits/stdc++.h>
#define MAXN 30
using namespace std;
char data[MAXN][MAXN];
bool ja_foi[MAXN][MAXN];

int n,m,maior,cont;
char agua,terra;
int x,y;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int solve(int i,int j)
{
	if(ja_foi[i][j]) return 0;
	if(i<0 || i>=n || j<0 || j>=m || data[i][j]!=terra) return 0;
	int qnt=1; ja_foi[i][j]=true;

    if(i-1>=0) qnt+=solve(i-1,j);
	if(i+1<n) qnt+=solve(i+1,j);

	qnt+=solve(i,(j-1+m)%m);
	qnt+=solve(i,(j+1)%m);
	return qnt;
}

bool blank=false;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	while(cin>>n>>m)
	{
        //if(blank) cin>>data[0];
        //blank=true;
        //getchar();
		for(int i=0;i<n;++i)
            for(int j=0;j<m;++j)
                cin>>data[i][j];
		cin>>x>>y;

		terra=data[x][y];
		memset(ja_foi,false,sizeof ja_foi); maior=0;

		int q=solve(x,y);

		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
			{
				if(!ja_foi[i][j])
					maior=max(maior,solve(i,j));
			}

		cout<<maior<<'\n';
	}


	return 0;
}
