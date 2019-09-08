#include <bits/stdc++.h>	//UVA 11991 - Easy Problem from Rujia Liu?
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 1000100
using namespace std;

vector<int> graph[N];
int n,m;
int x,k;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n>>m)
	{
		for(int i=0;i<N;++i)	graph[i].clear();
			
		for(int i=1;i<=n;++i)	
		{
			cin>>x;
			graph[x].pb(i);
		}

		for(int i=0;i<m;++i)
		{
			cin>>k>>x;
			if(graph[x].size() >= k)
				cout<<graph[x][k-1]<<"\n";
			else
				cout<<"0\n";
		}
	}
}
