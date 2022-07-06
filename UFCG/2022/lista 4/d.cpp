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

const int MAXN = 1e6 + 7;
bool exist[MAXN];
int bestGcd[MAXN];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, qnt = 0;
    cin>>n;
    vi v(n);
    for(int &x : v) {
    	cin>>x;
    	exist[x] = true;
    }

    for(int i=1;i<MAXN;++i) {
    	for(int j=i;j<MAXN;j+=i) {
    		if(exist[j])
    			bestGcd[i] = gcd(bestGcd[i],j);
    	}

    	qnt += bestGcd[i] == i;
    }

    cout<<qnt - n<<"\n";
}