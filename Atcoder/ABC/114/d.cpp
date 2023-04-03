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

const int N = 107;
int freq[N];
ll count(int x) {
	int ans = 0;
	for(int i=2;i<N;++i)
		if(freq[i] >= x-1) 
			ans++;	
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    for(int i=2;i<=n;++i) { //add prime factors
    	int x = i;
    	for(int j=2;j*j<=x;++j) {
			while(x%j == 0) {
				freq[j]++;
				x /= j;
			}
		}
		if(x) freq[x]++;
    }
    freq[1] = 0;

    //3.5.5 | 3.25 | 5.15 | 75
    ll ans = 0; 
    ans = ((count(3)-2)*(count(5)-1)*count(5))/2LL 
    		+ (count(3)-1)*count(25)
    		+ (count(5)-1)*count(15) + count(75);
    cout<<ans<<"\n";
}
