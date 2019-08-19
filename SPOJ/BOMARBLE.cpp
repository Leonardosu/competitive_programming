/*
	BOMARBLE SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define N 1010
using namespace std;
int f[N],n;

void make()
{
	f[0] = 5;
	for(int i=1;i<=N;++i)
		f[i] = f[i-1] + 3*i + 4;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	make();

	while(cin>>n && n)
	{
		cout<<f[n-1]<<"\n";
	}
}