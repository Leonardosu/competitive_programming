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
    for(char &c : s) {
    	freq[c-'a']++;
    }

    vi soltos;
    for(int i=0;i<26;++i) {
    	if(freq[i]%2) {
    		soltos.pb(i);
    	}
    }

    int qnt = soltos.size();
    int j = qnt - 1;
    for(int i=0;i<qnt;++i) {
    	if (i >= j) break;

    	freq[soltos[i]]++, freq[soltos[j]]--;
    	j--;
    }

    string left, right;
    for(int letra=0;letra<26;++letra) {
    	for(int i=0;i<freq[letra]/2;++i) {
    		left.pb(letra+'a');
    	}
    }

    right = left; reverse(ALL(right));

    if(qnt%2)
    	left.pb(soltos[qnt/2]+'a');

    cout<<left<<right<<"\n";
}