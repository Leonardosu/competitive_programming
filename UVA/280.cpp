#include <bits/stdc++.h>
#define MAXN 120
using namespace std;

int n,Q,op;
int atual,fim; // (atual) -> (fim)
bool ja_foi[MAXN]; // Marcar os manow
vector<int> vertex[MAXN];

void solve(int x)
{
	if(x!=atual || op!=-1)
		ja_foi[x]=true;

	op=1;
	int tamx=vertex[x].size();
	for(int i=0;i<tamx;++i)
		if(!ja_foi[ vertex[x][i] ])
			solve(vertex[x][i]);
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n && n) // Qnd n==0,fim da entrada
	{

		while(true)
		{
			cin>>atual;
			if(!atual) break; // Quando ini==0,acaba as atribuições!
			while(cin>>fim && fim)
				vertex[atual].push_back(fim);
		}

		cin>>Q; // Numero de consultas
		for(int i=0;i<Q;++i)
		{
			cin>>atual;
			op=-1;
			memset(ja_foi,0,sizeof ja_foi);
			solve(atual);
			vector<int> n_foi;

			for(int i=1;i<=n;++i) // coloco os cara ñ ligantes
				if(!ja_foi[i])
					n_foi.push_back(i);

			cout<<n_foi.size();					//Saída
			for(int j=0;j<n_foi.size();++j)
				cout<<" "<<n_foi[j];
			cout<<'\n';

		}

		for(int i=1;i<=n;i++) vertex[i].clear();
	}


	return 0;
}
