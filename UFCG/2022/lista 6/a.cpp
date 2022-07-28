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

const int N = 1e6 + 7;
string s;
bool vis[N];

void mark(int i, int j) {
	vis[i] = vis[j] = true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>s;
	int n = s.size(); 

	vector<pair<int, int>> comb = {{0,0}, {0,-1}, {1, 0}, {1, -1}};

	int l = 0, r = n - 1;
	while(l <= r) {
		if(l == r) {
			vis[l] = true;
			break;
		}

		for(auto &[x, y] : comb) {
			if(s[l+x] == s[r + y]){
				mark(l+x, r+y);
				break;
			}
		}

		l += 2, r -= 2;
	}

	for(int i=0;i<n;++i)
		if(vis[i])
			cout<<s[i];
	cout<<"\n";
}