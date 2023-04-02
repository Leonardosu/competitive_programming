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

double toYen(double btc) {
	/*
		1  = 380000.0
		btc = x
	*/
	return btc * 380000.0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;
    double ans = 0;
    for(int i=0;i<n;++i) {
    	double x;
    	cin>>x;
    	string s;
    	cin>>s;
    	if(s[0] == 'J')
    		ans += x;
    	else 
    		ans += toYen(x);
    }

    cout<<fixed<<setprecision(12);
    cout<<ans<<"\n";
}