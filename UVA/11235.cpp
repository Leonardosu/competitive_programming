#include <bits/stdc++.h> // O(N*Log + Q*Log) Segment Tree
#define e 2*no			// 11235 - Frequent values
#define d 2*no + 1
#define mid (ini+fim)/2
using namespace std;
const int N = 100010;

int tree[4*N + 500],n,q;
int aux[2*N + 100],v[2*N + 100];

void upd(int no,int ini,int fim,int pos,int x)
{
	if(ini == fim)
		tree[no] = x;
	else
	{
		if(pos <= mid) upd(e,ini,mid,pos,x);
		else upd(d,mid+1,fim,pos,x);
		tree[no] = max(tree[e],tree[d]);
	}
}

int query(int no,int ini,int fim,int l,int r)
{
	if(fim < l || ini > r) return -2*N;
	if(l<=ini && fim<=r) return tree[no];
	return max(query(e,ini,mid,l,r),query(d,mid+1,fim,l,r));
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(cin>>n && n)
	{
		int cnt = 1;
		int past;

		cin>>q>>v[1];		
		v[1]+=N;
		past = v[1];

		aux[v[1]] = 1;
		upd(1,1,n,1,cnt);

		for(int i=2;i<=n;++i)
		{
			cin>>v[i];
			v[i]+=N;
			aux[v[i]] = i;

			if(v[i] == past) cnt++;
			else
				cnt = 1,past = v[i];
			upd(1,1,n,i,cnt);
		}

		while(q--)
		{
			int ini,fim;
			cin>>ini>>fim;
			int c = aux[v[ini]];

			if(c > fim)
				cout<< fim - ini + 1<<"\n";
			else
				cout<<max(c - ini + 1,query(1,1,n,c+1,fim))<<"\n";			
		}
	}
	return 0;
}