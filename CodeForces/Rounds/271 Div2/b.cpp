#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n,q,x;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i) {
		cin>>v[i];
		if(i)
			v[i] += v[i-1];				
	}

	cin>>q;
	while(q--) {
		cin>>x;
		cout<<(lower_bound(v.begin(),v.end(),x)-v.begin())+1<<"\n";
	}

}