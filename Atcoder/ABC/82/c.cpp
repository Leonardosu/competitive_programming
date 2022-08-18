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
	map<int,int> qnt;
	int moves = 0;
	cin>>n;
	for(int i=0;i<n;++i){
		int x;
		cin>>x;
		qnt[x]++;
	}

	for(auto &[val, freq] : qnt) {
		if(freq < val)
			moves += freq;
		else if(freq > val)
			moves += freq - val;
	}

	cout<<moves<<"\n";
}