#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1e5+7;
int n, m, cor[N], anc[N];
bool cycle;
std::vector<int> g[N], cic;
 
bool dfs(int x, int p = 0){
	if (cor[x] == 2)
		return false;
	if (cor[x] == 1){
		if (cycle) return true;
		int cur = p;
		cic.push_back(x);
		while (cur != x){
			cic.push_back(cur);
			cur = anc[cur];
		}
		cic.push_back(x);
		return cycle = true;
	}
	cor[x] = 1;
	anc[x] = p;
	for (int i = 0; i < (int)g[x].size(); i++){
		int y = g[x][i];
		if (y == p) continue;
		dfs(y, x);
	}
	cor[x] = 2;
	return false;
}
 
int main(){
#ifdef LOCAL
	freopen("input", "r", stdin);
#endif
 
	scanf("%d %d", &n, &m);
 
	for (int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
 
	for (int i = 1; i <= n; i++){
		if (cor[i] != 2)
			dfs(i);
		if (cycle)
			break;
	}
 
	if (!cic.empty()){
		reverse(cic.begin(), cic.end());
		printf("%d\n", (int)cic.size());
		for (int i = 0; i < (int)cic.size(); i++){
			printf("%d ", cic[i]);
		}
		printf("\n");
	} else {
		printf("IMPOSSIBLE\n");
	}
 
	return 0;
}