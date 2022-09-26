#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5 + 7;

bool same;
int n,cnt;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n;
	v.resize(n);
	same = false; cnt = 0;
	int l = 0,r = 0;

	for(int i=0;i<n;++i) cin>>v[i];
	for(int i=0;i<n-1;++i) {
		if(v[i] >= v[i+1]) {
			if(!same) {
				l = i;
				cnt++;			
			}
			same = true;
		}
		else {

			if(same)
				r = i;
				
			same = false;

		}
	}
	if(same) r = n - 1;

	bool ok = true;
	if(cnt > 1) ok = false;
	reverse(v.begin() + l,v.begin() + r + 1);
	for(int i=0;i<n-1;++i)
		if(v[i] > v[i+1])
		{
			ok = false;
			break;
		}

	if(ok) cout<<"yes\n"<<l+1<<" "<<r+1<<"\n";
	else cout<<"no\n";
}