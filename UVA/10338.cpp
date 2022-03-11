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

const int N = 21;
ll fat[N];
int T = 1;

void solve_task()
{
	string word;
	cin>>word;
	int n = word.size();
	int freq[26];
	memset(freq, 0, sizeof(freq));
	for(char &c : word)
		freq[c-'A']++;

	ll total = fat[n];
	for(int i=0;i<26;++i)
		total /= fat[freq[i]];

	cout<<"Data set "<<T++<<": "<<total<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	fat[0] = fat[1] = 1;
	for(ll i=2;i<N;++i)
		fat[i] = fat[i-1] * i;

	int T_T = 1;
	cin>>T_T;
	while(T_T--)
		solve_task();
}