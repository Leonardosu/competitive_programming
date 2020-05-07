#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 1e6 + 10;
const ll MOD = 1e9 + 7;


ll ways[N];
int dice[] = {1,2,3,4,5,6};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	

	memset(ways,0,sizeof(ways));
	for(int i=1;i<=6;++i) ways[i] = 1;
	
	for(int now = 0;now < N;++now)
		for(int j=0;j<6;++j)
		{
			int xx = now - dice[j];
			if(xx < 0) continue;
			ways[now] = (ways[now] + ways[xx])%MOD;
		}
		
	int n;
	cin>>n;
	cout<<ways[n]<<"\n";
}
