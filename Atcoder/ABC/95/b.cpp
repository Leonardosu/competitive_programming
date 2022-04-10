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

	int n,x;
	cin>>n>>x;
	vi v(n);
	int sum = 0;
	for(auto &x:v)
	{
		cin>>x;
		sum += x;
	}
	x -= sum;
	int qnt = n + x/(*min_element(ALL(v)));
	cout<<qnt<<"\n";
}