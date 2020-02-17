#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"\n### _("<<x<<")_###\n";
using namespace std;

const int N = 1e5;
const int INF = 1e9;
typedef long long int ll;
typedef pair<int,int> ii;


int t;
string ss;
bool ok;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	char v[] = {'a','b','c'};

	while(t--)
	{
		cin>>ss;
		ok = true;
		for(int i=0;i<ss.size()-1;++i)
			if(ss[i] == ss[i+1] && ss[i] != '?')
			{
				ok = false;
				break;
			}
		
		if(ss[0] == '?')
		{
			if(ss.size() == 1)
				ss[0] = 'a';
			else
			{
				for(int i=0;i<3;++i)
					if(v[i] != ss[1])
						ss[0] = v[i];
			}
		}

		for(int i=1;i<ss.size()-1;++i)
		{
			if(ss[i] == '?')
			{
				for(int j=0;j<3;++j)
					if(v[j] != ss[i-1] && v[j] != ss[i+1])
						ss[i] = v[j];
			}
		}

		int aa = ss.size();

		if(ss[aa-1] == '?')
			for(int j=0;j<3;++j)
				if(v[j] != ss[aa-2])
					ss[aa-1] = v[j];

		if(ok) cout<<ss<<"\n";
		else cout<<"-1\n";
	}
}