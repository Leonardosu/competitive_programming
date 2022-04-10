#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
using namespace std;
 
const int N = 300;
const int INF = 1e8;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
 
int um,zero;
string entrada;
vector<int> v;
int t,n;
int quantidade = 0;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	
	cin>>t;
	for(int z=1;z<=t;++z)
	{
		quantidade = 0;
		um = zero = 0;
		cin>>n;
 
		bool impar = false;
		for(int i=0;i<n;++i)
		{
			cin>>entrada;
			for(int j=0;j<entrada.size();++j)
			{
				if(entrada[j] == '1')
					um++;
				if(entrada[j] == '0')
					zero++;
			}
 
			if(entrada.size()%2 == 1)
				impar = true;			
		}
 
		if(um%2 == 0 && zero%2 == 0)
			cout<<n<<"\n";
 
		else
		{
			if(impar)
				cout<<n<<"\n";
			else
				cout<<n-1<<"\n";
		}
	}
	
}