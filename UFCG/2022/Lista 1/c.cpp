#include "bits/stdc++.h" //Dima and Lisa
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

const int N = 1e9 + 7;
bool isPrime(int x)
{
	if(x <= 1) return false;

	for(int i=2;i*i<=x;++i)
		if(x%i == 0)
			return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	vi ans;

	if(isPrime(n))
		cout<<"1\n"<<n<<"\n";
	else if(isPrime(n-2))
		cout<<"2\n2 "<<n-2<<"\n";
	else
	{
		ans.pb(3);		
		n -= 3;
		for(int i=2;i<=n;++i)
			if(isPrime(n-i) && isPrime(i))
			{
				ans.pb(i);
				ans.pb(n-i);
				break;
			}
		cout<<"3\n";
		for(int &x : ans)
			cout<<x<<" ";
	}
		
}