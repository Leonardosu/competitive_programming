#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 10101
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int prefix[N];
int n,q;

void initi()
{
	int j = 1; int cost = 0 ;
	
	while(j <= N-50)
	{
		cost = prefix[j];

		for(int k=1;k<=5;++k)
			prefix[j+k] = cost+1;

		j+=5;

		for(int k=0;k<6;++k)
			prefix[j+k] = cost+2;
		j+=6;
	}
	prefix[7] = 3; prefix[1] = -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	initi();

	// cin>>q;
	// while(q--)
	// {
	// 	cin>>n;

	// 	if(n == 1 )
	// 		cout<<"-1\n";
	// 	else if(n == 7)
	// 		cout<<7<<"\n";
	// 	else
	// 		cout<<prefix[n]<<"\n";
	// }
	for(int i=1;i<=50;++i)
		cout<<i<<" "<<prefix[i]<<"\n";
}