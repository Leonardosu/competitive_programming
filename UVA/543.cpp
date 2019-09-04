#include <bits/stdc++.h> // UVA 543 - Goldbach's Conjecture
#define N 1000010
using namespace std;

typedef pair<int,int> ii;
vector<int> primos;

void crivo()
{
	bool mark[N];
	memset(mark,true,sizeof(mark));
	
	for(int i=3;i<N;i+=2)
		if(mark[i])
		{
			for(int j = 2*i;j<N;j+=i)
				mark[j] = false;
			primos.push_back(i);
		}
}

ii get(int val)
{
	int n = primos.size() - 1;
	int l,r;

	for(int i = 0;i<n;++i)
	{
		l = i; r = n;

		if(primos[i]>=val) return make_pair(-1,-1);
		int x = primos[i];

		while(l<=r)
		{
			int mid = (l+r)/2;
			if(x + primos[mid] == val) return (make_pair(x,primos[mid]));
			if(x + primos[mid] < val) l = mid + 1;
			else r = mid - 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	crivo();
	
	int x;
	bool flag = false;	

	while(cin>>x && x)
	{
		ii ans = get(x);
		if(ans.first == -1) cout<<"Goldbach's conjecture is wrong.";
		else cout<<x<<" = "<<ans.first<<" + "<<ans.second;
		cout<<"\n";
	}
}