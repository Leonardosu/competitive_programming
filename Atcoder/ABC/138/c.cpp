#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
vector<int> v;

int n,x;
double sum;
double ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n;
	while(n--)
	{
		cin>>x;
		v.push_back(x);
	}

	sort(v.begin(),v.end());
	sum = v[0];

	for(int i=1;i<v.size();++i)
	{
		sum = double(v[i]+sum)/2;
	}

	cout<<fixed<<setprecision(6);
	cout<<sum<<"\n";
}