/*
	PRIME1 SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;
set<int> sim,nao; // primos
int a,b,t;

bool check(int k)
{
	if(nao.find(k) !=nao.end()) return false;
	else if(sim.find(k) != sim.end()) return true;
	if(k%2==0) return false;

	for(int i=3;i<=sqrt(k);i+=2)
		if(k%i==0) 
			{
				nao.insert(k);
				return false;
			}
	sim.insert(k);
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	nao.insert(1);
	sim.insert(2);
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		for(int i=a;i<=b;++i)
			if(check(i))
				cout<<i<<"\n";
		cout<<"\n";
	}
}