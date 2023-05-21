#include <bits/stdc++.h>
#define e (no)*2
#define d (no)*2 + 1
#define mid (ini+fim)/2
#define all(x) x.begin(),x.end()
using namespace std;
const int N = 1e5 + 7;
typedef pair<int,int> ii;

int n,q,l,r;
int v[N];


int tree[4*N];

inline int gcd(int a,int b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}

void build(int no,int ini,int fim)
{
	if(ini == fim) tree[no] = v[ini];
	else
	{
		build(e,ini,mid);
		build(d,mid+1,fim);
		tree[no] = gcd(tree[e],tree[d]);
	}
}

int querie(int no,int ini,int fim,int l,int r)
{
	if(fim < l || ini > r) return 0;
	if(l<=ini && fim<=r) return tree[no];

	int a = querie(e,ini,mid,l,r);
	int b = querie(d,mid+1,fim,l,r);

	
	return gcd(a,b);
}

vector<ii>caras;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>v[i];
		caras.push_back({v[i],i});
	}


	build(1,1,n);
	sort(all(caras));

	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int atual = querie(1,1,n,l,r);
	 	ii xx = {atual,l};
	 	ii yy = {atual,r+1};

		int A = lower_bound(all(caras),xx) - caras.begin();
		int B = lower_bound(all(caras),yy) - caras.begin();

		cout<<r - l + 1 - (B - A)<<"\n";
	}
}
