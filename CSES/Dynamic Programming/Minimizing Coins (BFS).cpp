#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
const int N = 1e6;
const int INF = 1e9;
 
 
typedef long long int ll;
typedef pair<int,int> ii;
 
int dp[N];
 
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		
	for(int i=0;i<N;++i) dp[i] = INF;
	int n;
	cin>>n;
		
	queue<ii> fila;
	fila.push({n,0});
	while(!fila.empty())
	{
 
		int cnt = fila.front().second;
		int x = fila.front().first;
		fila.pop();
 
		if(cnt > dp[x]) continue;		
		dp[x] = cnt;
		if(x == 0) break;
 
		for(char c : to_string(x))
		{
			int xx = x - (c - '0');
			if(dp[xx] == INF)
			{
				dp[xx] = cnt + 1;
				fila.push({xx,cnt + 1});
			}
		}
	}
 
	
	cout<<dp[0]<<"\n";
}