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
	/*
		diff < k
			k - diff
		diff > k
			sort by freq
	*/


	int n, k;
	cin>>n>>k;

	map<int,int> freq;
	for(int i=0;i<n;++i) {
		int x;
		cin>>x;
		freq[x]++;
	}

	int diff = freq.size();
	if(freq.size() < k)
		cout<<0<<"\n";
	else {
		vector<int> q;
		for(auto &[x, a] : freq)
			q.pb(a);
		sort(ALL(q));

		int moves = 0;
		for(int i=0;i<diff-k;++i) {
			moves += q[i];
		}
		cout<<moves<<"\n";
	}
}