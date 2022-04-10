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
	int n = 3;
	string a,b,c;
	cin>>a>>b>>c;

	string s;
	s += a[0];
	s += b[1];
	s += c[2];
	cout<<s<<"\n";	
}