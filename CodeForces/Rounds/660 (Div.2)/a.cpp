#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int t,n;
const int maxn = 2e5 + 10;
bool ruim(int c)
{
	if(c == 6 || c == 10 || c == 14) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>t;
	while(t--)
	{
		cin>>n;
		int a = 6,b = 10,c = 14;
		n -= (a+b+c);

		if(n <= 0)
			cout<<"NO\n";
		else
		{
			// int c = n;
			if(ruim(n))
			{
				c = 15;
				n--;
				cout<<"YES\n";
				cout<<a<<" "<<b<<" "<<c<<" "<<n<<"\n";
			}
			else
			{
				cout<<"YES\n";
				cout<<"6 10 14 "<<n<<"\n";
			}
		}

	}

}