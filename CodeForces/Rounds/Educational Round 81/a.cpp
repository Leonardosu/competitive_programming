#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1;
const int INF = 1e9;

int s[123];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	
	s[2] = 1;
	s[3] = 7;
	s[4] = 4;	
	s[5] = 5;
	s[6] = 9;

	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		string number = "";
		for(int i=0;i<n/2;++i)
			number+='1';
		if(n%2 == 1)
			number[0] = '7';
		cout<<number<<"\n";
	}
}