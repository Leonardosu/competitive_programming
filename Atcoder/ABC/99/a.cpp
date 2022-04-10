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
	int n;
	cin>>n;
	if(n<1000)
		cout<<"ABC";
	else if(n < 2000)
		cout<<"ABD";
	else
		cout<<"ABE";
	cout<<"\n";
}