#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int E, limit;
int water1,water2;
int sugar1,sugar2;
int main() {
    cin.tie(0)->sync_with_stdio(0);

    	

    cin>>water1>>water2;
    cin>>sugar1>>sugar2;
    cin>>E>>limit;

    water1 *= 100;
    water2 *= 100;

    vector<int> waters, sugars;
	for(int a=0;a<=limit;a+=water1) 
		for(int b=0;b<=limit;b+=water2) {
			if(a + b > limit) continue;
			waters.pb(a + b);
		}

	for(int c=0;c<=limit;c+=sugar1)
		for(int d=0;d<=limit;d+=sugar2) {
			if(c + d > limit) continue;
			sugars.pb(c + d);
		}

    int cntwater = 0;
    int cntsugar = 0;
	for(auto curwater : waters)
		for(auto cursugar : sugars) {
			if(curwater + cursugar > limit) continue;
			if(curwater*E < 100*cursugar) continue;

			if(cursugar*(cntsugar + cntwater) 
				>= cntsugar*(curwater + cursugar)) {
				cntsugar = cursugar;
				cntwater = curwater;
			}
		}
    
    cout<<cntsugar + cntwater<<" "<<min(cntsugar, (cntwater/100)*E)<<endl;
}