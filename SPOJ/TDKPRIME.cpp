/*
	TDKPRIME SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define N 100000010 
using namespace std;

typedef long long ll;

ll crivo[N];
ll cont=1;
bool save[N];
int t,n;
void make()
{
	save[1]=1;
	for(ll i=2;i<=N;++i)
		if(!save[i])
		{
			crivo[cont]=i;
			cont++;
			for(ll j=2;i*j<=N;++j)
				save[i*j]=1;
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	make();

	for(int i=1;i<=201;i+=100)
		cout<<crivo[i]<<"\n";

}