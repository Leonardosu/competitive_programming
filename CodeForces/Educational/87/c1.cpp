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

const long double PI = acos(-1);

void solve_task() {
	int n;
	cin>>n;
	cout<<fixed<<setprecision(12);
	n *= 2;

	long double angle = (n-2) * 180.0 / n;
	angle /= 2.0;
	cout<<tan(angle * PI / 180.0)<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}