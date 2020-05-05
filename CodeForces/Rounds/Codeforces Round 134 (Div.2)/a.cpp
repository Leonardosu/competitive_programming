#include <bits/stdc++.h>
using namespace std;
const int N = 321;

int n,k;
int v[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>k;
	n = 2*n + 1;

	for(int i=1;i<=n;++i)
		cin>>v[i];
		
	for(int i=2;i<=n;i+=2)
	{
		v[i]--;
		if( v[i-1] >= v[i] || v[i+1] >= v[i])
			v[i]++;
		else
			k--;
		if(k == 0) break;
	}

	for(int i=1;i<=n;++i)
		cout<<v[i]<<" ";
	cout<<"\n";
}