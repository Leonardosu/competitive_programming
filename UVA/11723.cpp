#include <bits/stdc++.h> 
using namespace std;
int n,m;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t = 1;
	while(cin>>n>>m && (n+m))
	{
		int cnt = (n-1)/m;
		cout<<"Case "<<t<<": ";
		if(cnt > 26)
			cout<<"impossible\n";
		else
			cout<<cnt<<"\n";
		t++;
	}
}