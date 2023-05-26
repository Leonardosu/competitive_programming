#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
using namespace std;
const int N = 100000;
const int INF = 1e9;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
int f[12];
string number;
int n;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 
	for(int i=1;i<=9;++i)
		f[i] = 0;
 
	cin>>n;
	cin>>number;
 
	for(int i=1;i<=9;++i)
		cin>>f[i];
 
	for(int i=0;i<number.size();++i)
	{
		int x = int(number[i] - '0');
		if(f[x] > x)
		{
			for(int j=i;j<number.size();++j)
			{
				int zz = int(number[j] - '0');
				if(zz > f[zz]) break;
				number[j] = char(f[zz] + '0');			
			}
			break;
		}
	}

	cout<<number<<"\n";
}