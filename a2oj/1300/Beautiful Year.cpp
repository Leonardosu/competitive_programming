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


int freq[11];
inline bool beautiful(int x) {
	memset(freq, 0, sizeof freq);
	while(x > 0) {
		freq[x%10]++;
		x/=10;
	}

	for(int i=0;i<10;++i)
		if(freq[i] > 1)
			return false;
	return true;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;

	n++;
	while(true) {

		if(beautiful(n))
			break;
		n++;
	}

	cout<<n<<"\n";
}