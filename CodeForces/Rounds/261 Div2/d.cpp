#include <bits/stdc++.h>
#define e 2*no
#define d 2*no + 1
#define mid (ini+fim)/2
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1e6 + 7;
const int INF = 1e9;
typedef long long int ll;

ll BIT[N];
ll conta[N];
int a[N],b[N]; //prefix e suffixo
int v[N],n;
vector<int> caras;

void upd(int x,int val) {
	while(x < n) {
		BIT[x] += val;
		x += x&(-x);
	}
}

ll querie(int x) {
	ll ans = 0;
	while(x > 0) {
		ans += BIT[x];
		x -= x&(-x);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	caras.resize(n);

	for(int i=1;i<=n;++i) {
		cin>>v[i];
		caras[i-1] = v[i];
	}

	sort(all(caras));
	caras.erase(unique(all(caras)),caras.end());

	for(int i=1;i<=n;++i)
		v[i] = upper_bound(all(caras),v[i]) - caras.begin();	
	
	//#prefix
	for(int i=0;i<=n;++i)
		conta[i] = 0;

	for(int i=1;i<=n;++i) {
		int x = v[i];
		a[i] = conta[x] + 1;
		conta[x]++;
	}

	//#suffix
	for(int i=0;i<=n;++i)
		conta[i] = 0;	

	for(int i=n;i>=1;--i) {
		int x = v[i];
		b[i] = conta[x] + 1;
		conta[x]++;
	}

	
	for(int i=n;i>=1;--i) {
		int x = b[i];
		upd(x,1LL);
	}

	ll ans = 0;

	for(int i=1;i<=n;++i) {
		upd(b[i],-1LL);
		ans += querie(a[i] - 1);	
	}

	cout<<ans<<"\n";
}