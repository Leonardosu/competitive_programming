#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
double sum;
double x;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		sum+=1/x;
	}
	
	cout<<fixed<<setprecision(12);
	cout<<double(1/sum)<<"\n";
}