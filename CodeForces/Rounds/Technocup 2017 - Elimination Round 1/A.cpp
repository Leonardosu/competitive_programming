#include <bits/stdc++.h>
#define mp make_pair
using namespace std;

typedef long long int ll;
typedef pair<ll,string> stage;

string bfs(int a,int b) // "0" == 2*x  ;  "1" == 10*x + 1
{
	queue<stage> fila;
	fila.push(mp(a,""));

	while(!fila.empty())
	{
		ll number = fila.front().first;		string atual = fila.front().second;
		fila.pop();

		if(number > b) continue;

		if(number == b)
		{
			return atual;
		}

		fila.push(mp(number*2,atual+"0"));
		fila.push(mp(number*10+1,atual+"1"));
	}

	return "-1";
}

ll a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>a>>b;
	string ans = bfs(a,b);
	if(ans == "-1")
		cout<<"NO\n";
	else
	{
		cout<<"YES\n";
		cout<<ans.size() + 1<<"\n";
		cout<<a<<" ";
		for(int i=0;i<ans.size();++i)
		{
			if(ans[i] == '0')
				a*=2;
			else
				a*=10,a++;
			cout<<a<<" ";
		}
		cout<<"\n";
	}
}