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
ll gcd (ll a, ll b) { while (b) { a %= b,swap(a, b);}return a;}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	vector<int> nums;
	while(cin>>n && n)
	{
		nums.resize(n);

		for(int &x : nums)
			cin>>x;
		int qnt = 0;
		for(int i=0;i<n;++i)
			for(int j=i+1;j<n;++j)
				if(gcd(nums[i],nums[j]) == 1)
					qnt++;
		if(qnt == 0)
			cout<<"No estimate for this data set.";
		else
		{
			double ans = sqrt(6.0*n*(n-1)/(2.0*qnt));
			cout<<fixed<<setprecision(6);
			cout<<ans;
		}
		cout<<"\n";
	}
}