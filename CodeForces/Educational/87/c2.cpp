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
using ld = long double;

ld radian(ld x) {
	return x * PI / 180.0;
}

void solve_task() {
	int n;
	cin>>n;
	cout<<fixed<<setprecision(12);

	ld pivot = radian(45.0);
	ld angulo = 360.0 / (2.0*n);
	ld real = angulo * round(n / 4.0);

	ld lado = 0.5 / sin(radian(angulo/2.0));
	// cout<<angulo<<"#\n";
	//lei dos senos, para o lado esquerdo e direito

	ld ans = lado * (sin(radian(real)) + sin(radian(90.0 - real))) / sin(pivot);
	cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}