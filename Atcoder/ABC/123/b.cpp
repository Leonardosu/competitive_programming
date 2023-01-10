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

bool comp(int a, int b) {
	a = a%10;
	b = b%10;
	if(a == 0) a = 10;
	if(b == 0) b = 10;
	
	return (10 - a) < (10 - b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n = 5;
	vi v;
	int total = 0;
	for(int i=0;i<5;++i) {
		int x;
		cin>>x;

		v.pb(x);
	}

	sort(ALL(v), comp);
	n = v.size();
	for(int i=0;i<n-1;++i) {
		int x = v[i];
		total += x;
		if(x%10)
			total += 10 - x%10;
	}

	total += v.back();

	cout<<total<<"\n";
}