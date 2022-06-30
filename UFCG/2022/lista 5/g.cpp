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

struct person{
	ll hp, a, b;
};

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vector<person> v(n);
	for(int i=0;i<n;++i) {
		cin>>v[i].a>>v[i].b>>v[i].hp;
	}

	// int qnt = 0;
	vector<int> ans;
	for(int i=0;i<n;++i) {
		if(v[i].hp >= 0LL) {
			// cout<<v[i].hp<<" #\n";
			// qnt++;

			ans.pb(i);
			ll atk = v[i].a, bonus = 0LL;

			for(int j=i+1;j<n; ++j){
				ll &hp = v[j].hp;

				if(hp >= 0LL) {
					hp -= atk + bonus;
					if(hp < 0LL)
						bonus += v[j].b;
					if(atk)
						atk--;
				}
			}
		}
	}

	cout<<ans.size()<<"\n";
	for(int &x : ans)
		cout<<x+1<<" ";
	cout<<"\n";
	// cout<<qnt<<"\n";
}