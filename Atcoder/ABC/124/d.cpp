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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;

    s = s;
    int l = 0, usado = 0;
    int ans = 0, curr = 0;

    for(int i=0;i<n;++i) {
		if(s[i] == '0') {
			if(k == 0) {
				curr = 0;
				continue;
			}

			usado++;			
			while(l < i && usado > k) {
				if(s[l] == '0') {
					usado--;
					while(l<=i && s[l] == '0') {
						l++;
						curr--;
					}
				} else {
					l++, curr--;	
				}
			}

			while(i+1<n && s[i+1] == '0')
				i++, curr++;
		}

		curr++;
		if(usado <= k)
			ans = max(ans, curr); 	
    }

    cout<<ans<<"\n";
}