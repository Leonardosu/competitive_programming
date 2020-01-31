#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

typedef long long int ll;

const int N = 1;
const int INF = 1e9;
string number;
int n,um,zero;
ll ans,x;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;

	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		um = zero = ans = 0;
		cin>>number;

		ll dif = 0,now = 0;

		for(int i=0;i<number.size();++i)
		{
			if(number[i] == '0') dif++;
			else dif--;
		}

		bool flag = false;
		if(dif != 0)
		{
			for(int i=0;i<number.size();++i)
			{
				if(number[i] == '0') now++;
				else now--;	
				
				ll aux = x - now;
				if(aux%dif == 0)
				{
					ll k = aux/dif;
					if(k >= 0)
						ans++;
				}
			}			
		}

		else
		{
			ans = 0;
			for(int i=0;i<number.size();++i)
			{
				if(number[i] == '0') now++;
				else now--;	

				if(now == x)
				{
					ans = -1;
					flag = true;
					break;
				}
			}
		}

		if(x == 0 && !flag) ans++;
		cout<<ans<<"\n";
	}

}