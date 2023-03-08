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

void solve_task() {
	 double d, v, u;
	 cin>>d>>v>>u;
	 if(u == 0 || v == 0 || u*u <= v*v) {
	 	cout<<"can't determine\n";
	 } else {
	 	double t1 = d/u;
	 	double t2 = d / sqrt(u*u - v*v);
	 	cout<<fixed<<setprecision(3);
	 	cout<<fabs(t1-t2)<<"\n";
	 }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1; int id = 1;
    cin>>T_T;
    while(T_T--) {
    	cout<<"Case "<<id++<<": ";
        solve_task();
    }
}