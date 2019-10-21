//https://www.spoj.com/problems/LOSTNSURVIVED/
//Solution with DSU + STL MAP

#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define pii pair<int, int>
#define MAXN 100010


using namespace std;

int pai[MAXN], filhos[MAXN], maior, menor;

int find(int x)
{
	return pai[x] == x ? x : pai[x] = find(pai[x]);
}

map<int, int> mapa;

int join(int u, int v)
{
	u = find(u);
	v = find(v);

	if(u == v) return maior - menor;

	if(mapa[filhos[u]] == 1)
		mapa.erase(filhos[u]);
	else
		mapa[filhos[u]]--;

	if(mapa[filhos[v]] == 1)
		mapa.erase(filhos[v]);
	else
		mapa[filhos[v]]--;

	mapa[filhos[u] + filhos[v]]++;

	pai[u] = v;
	filhos[v] += filhos[u];

	maior = max(maior, filhos[v]);
	menor = mapa.begin()->first;

	return maior - menor;
}

int main(int argc, char** argv)
{
	optimize;

	int N, M, u, v;

	cin >> N >> M;

	menor = maior = 1;

	mapa[1] = N;

	for(int i = 1; i <= N; i++) pai[i] = i, filhos[i] = 1;


	while(M--)
	{
		cin >> u >> v;

		cout << join(u, v) << endl;
	}

	return 0;
}
