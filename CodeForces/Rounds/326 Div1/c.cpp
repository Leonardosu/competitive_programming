#include <bits/stdc++.h>
using namespace std;
 
int INF = 1000000000;
 
struct node{
	int j, ids[11] = {INF, INF, INF, INF, INF, INF, INF, INF, INF, INF, INF};
 
	void add(int x) {ids[10] = x; sort(ids, ids+11);}
	int size() {int j = 0; for(; ids[j] != INF && j < 10; j++); return j;}
};
 
inline node operator +(node a, node b) {for(int i = 0; i < 10; i++) b.add(a.ids[i]); return b;}
 
int level[100100];
node p[100100][21];
vector <int> ed[100100];
 
void dfs(int u, int v){
	
	level[u] = level[v] + 1;
 
	p[u][0].j = v;
 
	for(int i = 1; i <= 20; i++) {
		if(u == v) p[u][i] = p[u][i - 1];
		else p[u][i] = p[u][i - 1] + p[p[u][i - 1].j][i - 1];
		
		p[u][i].j = p[p[u][i - 1].j][i - 1].j;
	}
	
	for(auto e : ed[u]) if(e != v) dfs(e, u);
}
 
node lca(int u, int v){
	
	node ans;
	
	if(level[u] < level[v]) swap(u, v);
	
	for(int i = 0; 1 << i <= level[u] - level[v]; i++){
		if(1 << i & (level[u] - level[v])) {
			ans = ans + p[u][i];
			u = p[u][i].j;
		}
	}
	
	if(u == v) {ans = ans + p[u][0];}
	else{
		for(int i = 20; i >= 0; i--) if(p[u][i].j != p[v][i].j) {ans = ans + p[u][i] + p[v][i]; u = p[u][i].j; v = p[v][i].j;}
		ans = ans + p[u][0] + p[v][0] + p[p[u][0].j][0];
	}
	
	return ans;
}
 
int main(){
	
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	
	for(int i = 1; i < n; i++){
		int a, b;
		scanf(" %d %d", &a, &b);
		
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	
	for(int i = 0; i < m; i++){
		int x;
		scanf(" %d", &x);
		
		p[x][0].add(i + 1);
	}
	
	dfs(1, 1);
	
	for(int i = 0; i < q; i++){
		int u, v, a;
		scanf(" %d %d %d", &u, &v, &a);
		
		node ans = lca(u, v);
		
		a = min(a, ans.size());
		
		printf("%d", a);
		for(int k = 0; k < a; k++) printf(" %d", ans.ids[k]);
		printf("\n");
	}
	
	return 0;
}
