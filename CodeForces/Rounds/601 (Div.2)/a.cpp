#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int n,t;
int a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);


	cin>>t;
	while(t--)
	{
		cin>>a>>b;

		int dif = abs(a-b);
		int ans = 0;

		ans += dif/5;
		dif-= ans*5;

		int xx = dif/2;
		ans+= dif/2;
		dif = dif%2;
		ans+=dif;

		cout<<ans<<"\n";
	}

}