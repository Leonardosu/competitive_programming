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
    cin>>n;

    map<char,ll> freq;
    ll qnt = 0;
    for(int i=0;i<n;++i)
    {
    	string s;
    	cin>>s;
    	freq[s[0]]++;
    }

    int k = 5;
    vector<char> v = {'M', 'A', 'R', 'C', 'H'};
    for(int i=0;i<k;++i)
    	for(int j=i+1;j<k;++j)
    		for(int q=j+1;q<k;++q)
    			qnt += freq[v[i]]*freq[v[j]]*freq[v[q]];
    		
	cout<<qnt<<"\n";
}