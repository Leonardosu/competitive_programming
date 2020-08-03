#include <bits/stdc++.h>
#define N 1010
using namespace std;


int n,m,ans1,ans2;
int a[N],b[N];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n>>m;

	for(int i=0;i<m;++i)
	{
		cin>>a[i];
		b[i]=a[i];
	}

	for(int i=0;i<n;++i)
	{
		int maxi = 0; int mini = 9999;
		int z,y;
		for(int j=0;j<m;++j)
			if(a[j]>maxi && a[j]>0) maxi = a[j],z=j;
		ans1+=maxi,a[z]--;

		for(int j=0;j<m;++j)
			if(b[j]<mini && b[j]>0) mini = b[j],y=j;
		ans2+=mini,b[y]--;
	}

	cout<<ans1<<" "<<ans2<<"\n";
}