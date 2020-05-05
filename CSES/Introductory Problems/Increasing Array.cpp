#include <bits/stdc++.h>
using namespace std;

long long int cnt;
int n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	v.resize(n);
	cin>>v[0];
	for(int i=1;i<n;++i)
	{
		cin>>v[i];

		cnt += max(v[i-1]-v[i],0);
		v[i] = max(v[i-1],v[i]);
	}
	
	cout<<cnt<<"\n";
}
