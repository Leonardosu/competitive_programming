#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vector<ll> v(n+1);
	for(int i=1;i<=n;++i) cin>>v[i];

	if(n == 1)
	{
		cout<<"1 1\n1\n"<<"1 1\n1\n";
		cout<<"1 1\n"<<-(v[1]+2LL)<<'\n';
		return 0;
	}

	int fim = n;
	if(n%2 == 0)
	{
		cout<<"1 1\n";

		cout<<(v[1]%(n))*(n-1LL)<<"\n";
		v[1] += (v[1]%(n))*(n-1LL);

		cout<<"2 "<<n<<"\n";
		for(int i=2;i<=n;++i)
		{
			ll plus = (v[i]%(n))*(n-1LL);
			cout<< (v[i]%(n))*(n-1) <<" ";
			v[i] += plus;
		}

		cout<<"\n";

		cout<<"1 "<<n<<"\n";
		for(int i=1;i<=n;++i)
		{
			cout<<-v[i]<<" ";			
		}
		cout<<"\n";
	}
	else
	{

		cout<<"1 "<<n<<"\n";

		for(int i=1;i<=n;++i)
		{
			ll plus = ((n - 1) - v[i]%(n-1))*(n);
			cout<<plus<<" ";
			v[i] += plus;
		}

		cout<<"\n";
		cout<<2<<" "<<n<<"\n";
		for(int i=2;i<=n;++i) 
		    cout<<-v[i]<<" ";

		cout<<"\n";
		cout<<"1 1"<<"\n";
		cout<<-v[1]<<"\n";

		// cout<<"\n";	
		// cout<<"1 "<<n<<"\n";

		// cout<<"!!\n";
		// // n*=2;

		// for(int i=1;i<=n;++i)
		// {
		// 	ll plus = (v[i]%(2*n))*(n-1LL);
		// 	cout<< (v[i]%(2*n))*(n-1) <<" ";
		// 	v[i] += plus;
		// }
		// cout<<"\n\n";
		// for(int i=1;i<=n;++i)
		// 	cout<<v[i]<<" ";
		// n/=2;

	}
		
}