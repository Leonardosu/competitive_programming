#include <bits/stdc++.h> // UVA 624 - CD
#define mp make_pair	 // Bruteforce
using namespace std;

typedef long long int ll;
typedef pair<ll ,string> tipo;

vector<int> tracks;
int n,total,x;
tipo ans;

tipo solve(int i,ll soma,string pick)
{

	if(i>=n || soma > total)
	{
		pick[i] = '0';
		return mp(soma,pick);
	}

	if(soma + tracks[i] == total)
	{
		pick[i] = '1';
		return mp(soma + tracks[i], pick);
	}

	pick[i] = '0';
	tipo nbota = solve(i + 1,soma ,     		pick);
	if(soma + tracks[i] <= total)
	{
		pick[i] = '1';
		tipo bota =  solve(i + 1,soma + tracks[i] , pick);		
		return max(nbota,bota);
	}

	return nbota;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	while(cin>>total)
	{
		cin>>n; tracks.clear();

		for(int i=0;i<n;++i)
		{
			cin>>x;
			tracks.push_back(x);
		}

		string seq = "";
		for(int i=0;i<n;++i)
			seq+='0';

		ans = solve(0,0,seq);
		string resp = ans.second;

		for(int i=0;i<n;++i)
			if(resp[i] == '1')
				cout<<tracks[i]<<" ";
		cout<<"sum:"<<ans.first<<"\n";
		
	}

}