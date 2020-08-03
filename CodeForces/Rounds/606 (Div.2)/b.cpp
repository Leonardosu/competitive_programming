#include <bits/stdc++.h>
#define f fist
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 2e5 + 7;
const int INF = 1e9;
const int MOD = 1e9 + 7;

typedef long long int ll;
typedef pair<int,int> ii;

int t,n;
bool seen[N];
set<int> v,ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>n;
		v.clear();
		ans.clear();

		for(int i=0;i<n;++i)
		{
			int x;
			cin>>x;
			v.insert(x);
		}

		priority_queue<int> fila;
		int moves = 0;

		for(auto e : v)
			if(e%2 == 0)
				fila.push(e);

		while(!fila.empty())
		{
			int u = fila.top();
			fila.pop();
			if(ans.find(u) != ans.end()) continue;
			ans.insert(u);
			u/=2;
			if(u%2 == 0) fila.push(u);
			moves++;
		}
		cout<<moves<<"\n";
	}

}