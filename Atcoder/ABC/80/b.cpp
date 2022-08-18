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

	ll x;
	cin>>x;
	string s = to_string(x);
	ll sum = 0;
	for(char &c : s)
		sum += (c - '0');

	cout<<(x%sum == 0 ? "Yes" : "No")<<"\n";
}