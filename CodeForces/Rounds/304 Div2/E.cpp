#include <bits/stdc++.h>
using namespace std;
 
struct edge {int j, cap, flow, pos;};
 
vector <edge> ed[210];
int mans[210][210];
 
struct dinic{
	
	int level[210], p[210];
	dinic(){fill(level, level+210, 0); fill(p, p+210, 0);}
	
	void add(int i, int j, int w){ed[i].push_back({j, w, 0, (int)ed[j].size()}); ed[j].push_back({i, 0, w, (int)ed[i].size() - 1});}
	
	int bfs(int so, int sf){
		memset(level, -1, sizeof(level));
		
		queue <int> q;
		q.push(so);
		level[so] = 1;
		
		while(!q.empty()){
			
			int i = q.front();
			q.pop();
			
			for(edge e : ed[i]) if(e.cap && level[e.j] == -1){level[e.j] = level[i] + 1; q.push(e.j);}
		}
		return level[sf] != -1;
	}
	
	int dfs(int i, int sf, int f){
		if(i == sf) return f;
		
		for(; p[i] < (int)ed[i].size(); p[i]++){
			edge& e = ed[i][p[i]];
			
			if(e.cap == 0 || level[e.j] <= level[i]) continue;
			
			int flow = dfs(e.j, sf, min(f, e.cap));
			if(!flow) continue;
			
			e.cap -= flow;
			ed[e.j][e.pos].cap += flow;
			
			return flow;
		}
		return 0;
	}
	
	void flow(int so, int sf){
		
		int max_flow = 0;
		
		while(bfs(so, sf)){
			memset(p, 0, sizeof(p));
			int f;
			while((f = dfs(so, sf, 1e9))) max_flow++;
		}
	}
} ans;
 
int main(){
	
	int n, m, ini[200], end[200];
	scanf("%d %d", &n, &m);
	
	for(int i = 0; i < n; i++) {scanf(" %d", &ini[i + 1]); ans.add(i + 1, i + n + 1, ini[i + 1]);}
	for(int i = 0; i < n; i++) {scanf(" %d", &end[i + 1]); ans.add(i + n + 1, 2 * n + 1, end[i + 1]);}
	for(int i = 0; i < n; i++) {ans.add(0, i + 1, ini[i + 1]);}
	
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		
		ans.add(a, b + n, 1e9);
		ans.add(b, a + n, 1e9);
	}
	
	ans.flow(0, 2 * n + 1);
		
	for(int i = 1; i <= n; i++){
		for(auto e : ed[i]){
			if(e.j > n) mans[i][e.j - n] = ed[e.j][e.pos].cap;
		}
	}
	
	int v = 1;
	
	for(auto e : ed[2 * n + 1]) v = v && (e.cap == end[e.j - n]);
	for(auto e : ed[0]) v = v && (e.cap == 0);
	
	if(v){
		printf("YES\n");
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) printf("%d ", mans[i][j]);
			printf("\n");
		}
	}
	else printf("NO\n");
	
	return 0;
}
