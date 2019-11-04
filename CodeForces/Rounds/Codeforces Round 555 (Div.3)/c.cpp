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

vector<int> v;

int ans;
int x,n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x;
		v.pb(x);		
	}
	
	int l = 0, r = n-1;
	string ans = "";
	int last = 0,moves = 0;

	while(l<=r)	
	{
		if(v[l] <= last && v[r] <= last) break;

		if(l == r)
		{
			ans+="L";
			moves++;
			break;
		}

		if(v[l] < v[r])
		{
			if(v[l] > last)
			{
				last = v[l];
				ans+="L";
				l++;
			}
			else if(v[r] > last)
			{
				last = v[r];
				ans+="R";
				r--;
			}
			else
				break;
		}

		else if(v[l] > v[r])
		{
			if(v[r] > last)
			{
				last = v[r];
				ans+="R";
				r--;
			}
			else if(v[l] > last)
			{
				last = v[l];
				ans+="L";
				l++;
			}
			else
				break;
		}

		else
		{
			int A = moves;
			int B = moves;

			string SA = ans;
			string SB = ans;
			int aux = last;			

			while(v[l] > aux)
			{
				aux = v[l];
				SA+="L";
				A++;
				l++;
			}
			
			while(v[r] > last)
			{
				last = v[r];
				SB+="R";
				B++;
				r--;
			}

			if(A > B)
			{
				cout<<A<<"\n";
				cout<<SA<<"\n";
			}
			else
			{
				cout<<B<<"\n";
				cout<<SB<<"\n";
			}
			return 0;
		}
		moves++;
	}

	cout<<moves<<"\n";
	cout<<ans<<"\n";
}