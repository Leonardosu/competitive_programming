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
	int TT = 1;
	// cin>>TT;
	while(TT--)
	{
		string s;
		int k;
		cin>>s>>k;
		sort(ALL(s));
		k--;

		do{
			if(!k) break;
			k--;
		}while(next_permutation(ALL(s)));

		cout<<s<<"\n";
	}	
}