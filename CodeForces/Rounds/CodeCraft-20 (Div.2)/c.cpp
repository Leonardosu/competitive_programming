#include <bits/stdc++.h>

const int N = 1e6 + 7;
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int n,m;
int a[N],b[N];
ll p;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m>>p;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<m;++i) cin>>b[i];

	int i = 0, j = 0;
	while(a[i]%p == 0) i++;
	while(b[j]%p == 0) j++;
	cout<<i+j<<"\n";
}