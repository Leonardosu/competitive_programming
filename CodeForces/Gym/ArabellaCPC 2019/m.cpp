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

	string s;
	cin>>s;
	int freq[26]; memset(freq, 0, sizeof freq);

	for(char &c : s)
		freq[c-'a']++;

	for(int i=1;i<26;++i) {
		freq[i] += freq[i-1]/2;
		freq[i-1] = freq[i-1]%2;
	}

	string result;
	for(int i=0;i<26;++i) {
		// if(freq[i])
			// cout<<freq[i]<<"]\n";
		result += string(freq[i], i + 'a');
	}
	reverse(ALL(result));
	cout<<result<<"\n";	
}