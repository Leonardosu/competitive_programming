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

	int d,n;
	cin>>d>>n;

	int multi = 1;
	for(int i=1;i<=d;++i) multi *= 100;

	int Nth = (n + (n)/100);

	cout<<Nth*multi<<"\n";
}