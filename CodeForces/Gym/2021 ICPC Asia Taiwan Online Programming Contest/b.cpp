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

int solve(int x) {
	int sum = 0;
	for(int i=1;i*i<=x;++i) {
		if(x%i == 0) {
			sum += i;
			if(x/i != i)
				sum += x/i;
		}

	}
	return sum - x;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
    	int x;
    	cin>>x;
    	int y = solve(x);
    	if(y > x)
    		cout<<"abundant";
    	else if(y == x)
    		cout<<"perfect";
    	else
    		cout<<"deficient";
    	cout<<"\n";
    }
}