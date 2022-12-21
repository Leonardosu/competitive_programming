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
    string s;
    cin>>n>>s;

    int x = 0, y = 0;
    int k = 0;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, -1, 0, 1};
    for(int i=0;i<n;++i) {
    	if(s[i] == 'S') {
    		x += dx[k];
    		y += dy[k];
    	} else {
    		k++;
    		if(k >= 4)
    			k-=4;
    	}
    }

    cout<<x<<" "<<y<<"\n";
}