#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int n;
	cin>>n;
	vector<int> v(n);

	for(int i=0;i<n;++i) cin>>v[i];
	sort(all(v));

	int cnt = 1;
	for(int i=1;i<n;++i)
		if(v[i] != v[i-1]) cnt++;
	cout<<cnt<<"\n";
}