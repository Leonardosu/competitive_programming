#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve_task()
{
	map<int,int> freq1,freq2;
	int n;
	cin>>n;
	vector<pii> v;
	vi a(n), b(n);
	bool valid = true;
	for(int i=1;i<=n;++i) {
		freq1[-i] = 1;
		freq2[-i] = 1;
	}

	for(int i=0;i<n;++i) {
		int x;
		cin>>x;

		if (freq1.count(-x)) {
			a[i] = x;
			freq1.erase(-x);
		} else if(freq2.count(-x)) {
			b[i] = x;
			freq2.erase(-x);
		} else {
			valid = false;
		}
	}	

	for(int i=0;i<n;++i) {
		if(a[i] == 0) {
			auto it = freq1.lower_bound(-b[i]);
			if (it == freq1.end()) {
				valid = false;
				break;
			}

			int y = it->first;
			freq1.erase(y);
			a[i] = -y;
		} else if(b[i] == 0) {
			auto it = freq2.lower_bound(-a[i]);
			if (it == freq2.end()) {
				valid = false;
				break;
			}
			
			int y = it->first;
			freq2.erase(y);
			b[i] = -y;
		}
	}

	if(valid) {
		cout<<"YES\n";
		for(int x : a)
			cout<<x<<" ";
		cout<<"\n";

		for(int x : b)
			cout<<x<<" ";
		cout<<"\n";
	} else {
		cout<<"NO\n";
	}
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}