#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<int> v;
	int n,pos = -1;

	cin>>n;
	v.resize(n-1);
	for(int i=0;i<n-1;++i) cin>>v[i];
	sort(v.begin(),v.end());

	for(int i=0;i<n-1;++i)
		if(v[i] != i + 1)
		{
			pos = i + 1;
			break;
		}
	if(pos == -1) pos = n;
	cout<<pos<<"\n";
	
}