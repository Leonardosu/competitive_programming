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

	int n;
	int x = 0, y = 0;
	int t = 0;
	cin>>n;

	bool valid = true;
	for(int i=0;i<n;++i) {
		int c, a, b;
		cin>>c>>a>>b;
		int dist = abs(a - x) + abs(b - y);
		int plus = c - t - dist;
		if (t + dist > c || (plus > 0 && plus%2 == 1)) {
			valid = false;
		}

		x = a, y = b, t = c;
	}

	cout<<(valid ? "Yes" : "No")<<'\n';
}