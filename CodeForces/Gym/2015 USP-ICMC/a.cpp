#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	const double PI = acos(-1);

	long double n,r,R,angle;
	cin>>n>>R>>r;

	angle = 360.0/(2.0*n);
	double S1 = r*R*sin(angle*2.0*PI/360.0);
	cout<<fixed<<setprecision(8);

	cout<<S1*n<<"\n";
}
