#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline void add(pii &p, int x)
{
	if(abs(x) == 2)
		p.s++;

	if(x < 0)
		p.f *= -1;
}

void solve_task()
{
	int n;
	cin>>n;

	vector<ll> v(n);
	vector<pii> pre(n),suf(n);
	for(ll &x : v)
		cin>>x;

	pii id = {n,0};
	pii neutro = {1, 0};
	ll best = 0;

	for(int i=0,j=0;i<n;++i)
	{
		while(i<n && v[i]==0)
			i++;

		if(i==n) break;
		
		j = i;
		pii prod = {1,0};
		add(prod, v[i]);
		while(j+1<n && v[j+1]!=0)
			j++, add(prod, v[j]);
			
		// i..-..-.j
		// cout<<"Looking ("<<i<<","<<j<<")\n";
		if(prod.f < 0)
		{
			pre[i] = {1, 0};
			add(pre[i], v[i]);

			for(int k=i+1;k<=j;++k)
			{
				pre[k] = pre[k-1];
				add(pre[k], v[k]);
			}

			suf[j] = {1, 0};
			add(suf[j], v[j]);

			for(int k=j-1;k>=i;--k)
			{
				suf[k] = suf[k+1];
				add(suf[k], v[k]);
			}

			for(int k=i;k<=j;++k)
				if(v[k] < 0)
				{
					pii left =  (k == i ? neutro : pre[k-1]);
					pii right = (k == j ? neutro : suf[k+1]);

					if(left.f > 0 && left.s > best)
						best = left.s, id = {i, n-k};

					if(right.f > 0 && right.s > best)
						best = right.s, id = {k+1, n-j-1};
				}
		}
		else if(prod.s > best)
			best = prod.s, id = {i,n-j-1};	

		i = j;
	}

	// cout<<best<<" | ";
	cout<<id.f<<" "<<id.s<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}