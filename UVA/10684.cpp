#include <bits/stdc++.h>
#define MAXN 10010

using namespace std;

int v[MAXN],n,k;

int sum()
{
	int maior=0,resp=0;
	for(int i=1;i<=n;++i)
	{
		maior=max(maior+v[i],0);
		resp=max(maior,resp);
	}
	return resp;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n && n)
	{
		for(int i=1;i<=n;++i)
			cin>>v[i];
		k=sum();
		if(k!=0)
			cout<<"The maximum winning streak is "<<k<<".\n";
		else
			cout<<"Losing streak.\n";
	}

	return 0;
}