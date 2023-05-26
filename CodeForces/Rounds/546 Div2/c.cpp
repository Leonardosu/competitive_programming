#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 2210;
const int INF = 1e9 + 7;
typedef pair<int,int> ii;
typedef long long int ll;
inline ll gcd(ll a,ll b){	while(b){	a%=b;	swap(a,b);	}	return a;	}

int a[N][N],b[N][N];
int n,m;
map<int,int> cnt1,cnt2;
vector<int> A[N],B[N];
int total = 0;


bool check()
{	
	if(a[1][1] != b[1][1] || a[n][m] != b[n][m]) return false;
	return true;
}


void pegaosbagui(int a[N][N],vector<int> diagonal[N])
{
	total = 0;

	for(int j=2;j<=m;++j)
	{
		int pos = j;		
		int cnt = 0;
		total++;
		while(j-cnt >= 1 && cnt + 1 <= n)
		{
			diagonal[total].pb(a[1+cnt][j-cnt]);
			cnt++;
		}
	}

	for(int i=2;i<n;++i)
	{
		int cnt = 0;
		total++;
		while(i+cnt <= n && m-cnt>=1)
		{
			diagonal[total].pb(a[i+cnt][m-cnt]);
			cnt++;
		}
	}	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);	
	int casos;
	bool ok = true;

	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cin>>a[i][j];
	}

	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cin>>b[i][j];
		
	}

	if(!check())
	{
		cout<<"NO\n";
		return 0;
	}

	
	// int total = m + n - 2;

	pegaosbagui(a,A);
	pegaosbagui(b,B);
	bool can = true;
	// total/=2;

	for(int i=1;i<=total;++i)
	{
		sort(all(A[i]));
		sort(all(B[i]));
		if(A[i].size() != B[i].size())
		{
			cout<<"NO\n";
			return 0;
		}

		for(int j=0;j<A[i].size();++j)
		{
			if(A[i][j] != B[i][j])
			{
				cout<<"NO\n";
				return 0;
			}

		}

	cout<<"YES\n";
}