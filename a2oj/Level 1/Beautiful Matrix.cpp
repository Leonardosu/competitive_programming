#include <bits/stdc++.h>
using namespace std;

int mat[10][10];
int n,x,y;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	

	for(int i=1;i<=5;++i)
		for(int j=1;j<=5;++j)
		{
			cin>>mat[i][j];
			if(mat[i][j]==1)
			{
				x=i; y=j;
			}
		}

	cout<<abs(x-3)+abs(y-3)<<'\n';

	return 0;
}