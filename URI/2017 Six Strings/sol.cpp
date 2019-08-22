/*						
	2017 - Six Strings
	Leonardo Su 	
	3/16/17, 3:08:46 PM
*/
#include <bits/stdc++.h>
using namespace std;
string a,b;
int k,id,maior,qnt;

void solve(int x)
{
	qnt = 0;
	for(int i=0;i<a.size();++i)
		if(a[i] != b[i])
			qnt++;
	if(qnt<maior)
		maior = qnt,id = x + 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>a;
	cin>>k;
	maior = a.size();

	for(int i=0;i<5;++i)
	{
		cin>>b;
		solve(i);
	}

	if(maior>k)
		cout<<"-1\n";
	else
		cout<<id<<"\n"<<maior<<"\n";
}