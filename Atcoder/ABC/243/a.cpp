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
    int total = 0;
    array<int,3> v;
    for(int &x : v)
    {
    	cin>>x;
    	total += x;
    }

    n = n%total;
    array<string,3> as = {"F","M","T"};
    for(int i=0;i<3;++i)
    {
    	n-=v[i];
    	if(n < 0)
    	{
    		cout<<as[i]<<"\n";
    		return 0;
    	}
    }

}