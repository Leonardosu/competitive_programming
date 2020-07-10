#include <bits/stdc++.h>
using namespace std;
const int N = 100010;

int n,m;
int pai[N],lv[N],cnt[N];

int find(int x)
{
	if(x == pai[x]) return x;
	return pai[x] = find(pai[x]);
}

void join(int x,int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return ;
	if(lv[x] > lv[y]) swap(x,y);
	if(lv[x] == lv[y]) lv[y]++;	
	pai[x] = y;	
	cnt[y] += cnt[x];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		pai[i] = i,lv[i] = 0,cnt[i] = 1;
	
	int rest = n;
	int maior = 1;

	for(int i=0;i<m;++i)
	{
		int a,b;
		cin>>a>>b;
		if(find(a) != find(b))
			rest--;
		join(a,b);
		if(cnt[find(a)] > maior)
			maior = cnt[find(a)];
		cout<<rest<<" "<<maior<<"\n";
	}
}