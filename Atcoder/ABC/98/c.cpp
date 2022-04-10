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

	string s;
	int n;
	cin>>n;
	cin>>s;
	int left[n],right[n];

	left[0] = 0;
	right[0] = 0;

	for(int i=0;i<n;++i)
	{
		if(i)
			left[i] = left[i-1],right[i] = right[i-1];

		if(s[i] == 'W')
			left[i]++;
		else
			right[i]++;
	}
	int ans = n;

	for(int i=0;i<n;++i)
	{
		int esquerda = 0,direita = 0;

		if(i-1 >= 0)
			esquerda = left[i-1];	
		direita = right[n-1] - right[i];
				
		ans = min(ans,esquerda + direita);
	}
	cout<<ans<<"\n";
}