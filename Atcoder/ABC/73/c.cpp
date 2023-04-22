#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    set<int> num;
    int n;
    cin>>n;

    while(n--) {
    	int x;
    	cin>>x;
    	if(present(num, x))
    		num.erase(x);
    	else
    		num.insert(x);
    }

    cout<<sz(num)<<endl;
}