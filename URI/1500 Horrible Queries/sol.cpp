#include <bits/stdc++.h>
#define mid (ini+fim)/2
#define N 100100
using namespace std;

typedef long long int ll;

ll tree[4*N],lazy[4*N]; // segtree
ll v[N];
ll n,q,t;

void build(int no,int ini,int fim)
{
	lazy[no] = 0;
	if(ini == fim) tree[no] = v[ini];
	else
	{
		build(2*no,ini,mid); build(2*no+1,mid+1,fim);
		tree[no] = tree[2*no] + tree[2*no+1];
	}
}

void propraga(int no,ll ini,ll fim)
{
	if(lazy[no] != 0 )
	{
		tree[no]+=(fim-ini+1)*lazy[no];
		if(ini!=fim)
		{
			lazy[2*no]+=lazy[no];
			lazy[2*no+1]+=lazy[no];
		}
		lazy[no] = 0;
	}	
}

void upd(int no,ll ini,ll fim, ll l, ll r, ll val)
{
    propraga(no,ini,fim);

    if(fim<l || ini>r)	return;

    if(l<=ini && fim<=r)
    {
        tree[no] += (fim - ini + 1) * val;

        if(ini != fim)
        {
            lazy[no*2] += val;
            lazy[no*2+1] += val;
        }
        return;
    }

    upd(no*2, ini, mid, l, r, val);
    upd(no*2 + 1, mid + 1, fim, l, r, val);
    tree[no] = tree[no*2] + tree[no*2+1];       
}

ll query(int no,ll ini,ll fim,ll l,ll r)
{
    propraga(no,ini,fim);      
    if(fim<l || ini>r)	return 0;

    if(l<=ini && fim<=r)	return tree[no];

    ll p1 = query(no*2, ini, mid, l, r);
    ll p2 = query(no*2 + 1, mid + 1, fim, l, r);
    return (p1 + p2);
}
void swapp(ll a,ll b)
{
	ll aux = a;
	if(a<b)
		a = b,b = aux;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>t;

	while(t--)
	{
  		cin>>n>>q;

  		for(int i=0;i<=n;++i)
  			v[i] = 0;

		build(1,1,n);
  		ll tt,a,b;
  		ll x;

		while(q--)
		{
			cin>>tt;
			if(tt == 1)
			{
				cin>>a>>b;
				cout<<query(1,1,n,a,b)<<"\n";
			}
			else
			{
				cin>>a>>b>>x;
				upd(1,1,n,a,b,x);
			}
		}
  	}
}