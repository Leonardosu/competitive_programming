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


bool get()
{
	int x;
	cin>>x;
	if(x == 1)
		return true;
	return false;
}

void query(int l,int r)
{
	cout<<l<<" "<<r<<endl;
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	int l = 1, r = n;
	while(l < r)
	{
		int mid = (l+r)/2;

		query(l,mid);

		bool esquerda = get();
		if(esquerda)
			r = mid;
		else
			l = mid + 1;
	}

	cout<<"! "<<l<<endl;
}
