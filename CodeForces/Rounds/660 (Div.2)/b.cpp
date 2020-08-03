#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


string number;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t;
	cin>>t;
	int n;
	while(t--)
	{
		cin>>n;
		int total = 4*n;

		int nove = (total - n)/4;
		int oito = (total - 4*nove)/4;

		number = "";

		for(int i=0;i<nove;++i)
			number.push_back('9');

		for(int i=0;i<oito;++i)
			number.push_back('8');

		// :if(resto == )
		cout<<number<<"\n";
	}
}