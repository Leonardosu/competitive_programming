#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 400100;
const int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;

int n,best,x,y;
int cnt[N],aux = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>x;
	best = 0;
	for(int i=0;i<n;++i)
	{
		cin>>y;
		cnt[y%x]++;
		while(cnt[best%x] > 0)
		{
			cnt[best%x]--;
			best++;
		}
		cout<<best<<"\n";
	}
}