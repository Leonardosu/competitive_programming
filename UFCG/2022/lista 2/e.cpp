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

string s;
int freq[26];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>s;
	for(char &c : s) {
		freq[c-'a']++;
	}

	vector<char> v;
	for(int i=0;i<26;++i) {
		if(freq[i]%2) {
			v.pb(i + 'a');
		}
	}

	//a, b, b, a
	int j = v.size() - 1;
	for(int i=0;i<(int)v.size();++i) {
		if(i >= j) break;

		int a = v[i] - 'a', b = v[j] - 'a';
		freq[a]++;
		freq[b]--;
		j--;
	}

	string ans = "";
	for(int i=0;i<26;++i) {
		for(int j=0;j<freq[i]/2;++j) {			
			ans += i + 'a';
		}
	}
	
	string backAns = ans;
	reverse(ALL(backAns));
	if(v.size()%2 == 1)
		ans += v[v.size()/2];

	cout<<ans + backAns<<"\n";
}