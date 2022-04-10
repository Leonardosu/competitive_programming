#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5;
const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}



int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int t;
	cin>>t;

	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int ans = 0;
		int qnt = n/k;


		if(qnt >= m)
		{
			cout<<m<<'\n';
			continue;			
		}

		ans = qnt;

		m-=qnt;

		int aux = 0;
		aux = (m + k - 2)/(k-1);
		cout<<ans - aux<<"\n";
	}

}