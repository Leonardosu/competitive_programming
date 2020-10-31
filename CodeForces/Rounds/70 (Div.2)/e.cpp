#include <bits/stdc++.h>
using namespace std;

vector <pair<int, int>> people;
int ed[210][210], times[210][210], n, t, INF = 1e9, vis[210][210], id = 100, idx[210][210];

char m[210][200], lab[210][210];

pair <int, int> where(){
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(m[i][j] == 'Z') return {i, j};
	return {0, 0};
}

void labs_idx(){
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {
		if(lab[i][j] - '0' > 0 && lab[i][j] - '0' < 10) {
			idx[i][j] = ++id; ed[idx[i][j]][209] = lab[i][j] - '0';
		}
	}
}

int can(int i, int j){
	if(i < 0 || j < 0 || i == n || j == n) return 0;
	if(m[i][j] == 'Y' || m[i][j] == 'Z') return 0;
	return 1;
}

void bfs(){
	
	pair <int, int> x = where();
	
	queue <pair<int , pair<int, int>>> q;
	
	q.push({0, {x.first, x.second}});
	times[x.first][x.second] = 0;
	
	while(!q.empty()){
		int d = q.front().first, i = q.front().second.first, j = q.front().second.second;
		q.pop();
		
		if(can(i + 1, j) && times[i + 1][j] == 0) {q.push({d + 1, {i + 1, j}}); times[i + 1][j] = d + 1;}
		if(can(i - 1, j) && times[i - 1][j] == 0) {q.push({d + 1, {i - 1, j}}); times[i - 1][j] = d + 1;}
		if(can(i, j + 1) && times[i][j + 1] == 0) {q.push({d + 1, {i, j + 1}}); times[i][j + 1] = d + 1;}
		if(can(i, j - 1) && times[i][j - 1] == 0) {q.push({d + 1, {i, j - 1}}); times[i][j - 1] = d + 1;}
	}
	
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) {if(times[i][j] == 0) times[i][j] = t * (i != x.first || j != x.second); times[i][j] = min(times[i][j], t);}
}

void make_edge(){
	
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(m[i][j] - '0' > 0 && m[i][j] - '0' < 10) people.push_back({i, j});
	
	id = (int)people.size();
	labs_idx();
	
	for(int k = 1; k <= (int)people.size(); k++){
		pair <int, int> l = people[k - 1];
		
		ed[0][k] = m[l.first][l.second] - '0';
		
		queue <pair<int , pair<int, int>>> q;
		
		for(int i = 0; i < 210; i++) for(int j = 0; j < 210; j++) vis[i][j] = 0;
		
		q.push({0, {l.first, l.second}});
		vis[l.first][l.second] = 1;
		
		if(idx[l.first][l.second]) ed[k][idx[l.first][l.second]] = m[l.first][l.second] - '0';
		
		while(!q.empty()){
			int d = q.front().first, i = q.front().second.first, j = q.front().second.second;
			q.pop();
			
			if(can(i + 1, j) && !vis[i + 1][j] && d + 1 <= times[i + 1][j]) {
				if(d + 1 < times[i + 1][j]) q.push({d + 1, {i + 1, j}});
				if(idx[i + 1][j]) ed[k][idx[i + 1][j]] = m[l.first][l.second] - '0';
				
				vis[i + 1][j] = 1;
			}
			if(can(i - 1, j) && !vis[i - 1][j] && d + 1 <= times[i - 1][j]) {
				if(d + 1 < times[i - 1][j])q.push({d + 1, {i - 1, j}});
				if(idx[i - 1][j]) ed[k][idx[i - 1][j]] = m[l.first][l.second] - '0';
				vis[i - 1][j] = 1;
			}
			if(can(i, j + 1) && !vis[i][j + 1] && d + 1 <= times[i][j + 1]) {
				if(d + 1 < times[i][j + 1])q.push({d + 1, {i, j + 1}});
				if(idx[i][j + 1]) ed[k][idx[i][j + 1]] = m[l.first][l.second] - '0';
				vis[i][j + 1] = 1;
			}
			if(can(i, j - 1) && !vis[i][j - 1] && d + 1 <= times[i][j - 1]) {
				if(d + 1 < times[i][j - 1])q.push({d + 1, {i, j - 1}});
				if(idx[i][j - 1]) ed[k][idx[i][j - 1]] = m[l.first][l.second] - '0';
				vis[i][j - 1] = 1;
			}
		}
	}
}

struct edge {int j, cap, flow, pos;};
 
struct dinic{
	
	int level[210], p[210];
	vector <edge> ed[210];
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
			
			long long flow = dfs(e.j, sf, min(f, e.cap));
			if(!flow) continue;
			
			e.cap -= flow;
			ed[e.j][e.pos].cap += flow;
			
			return flow;
		}
		return 0;
	}
	
	int flow(int so, int sf){
		
		int max_flow = 0;
		
		while(bfs(so, sf)){
			memset(p, 0, sizeof(p));
			int f;
			while((f = dfs(so, sf, 1e9))) max_flow += f;
		}
		
		return max_flow;
	}
} ans;

int main(){
	
	scanf("%d %d", &n, &t);
	
	for(int i = 0; i < n; i++) scanf("\n%s", m[i]);
	
	scanf("\n");
	
	for(int i = 0; i < n; i++) scanf("\n%s", lab[i]);
	
	bfs();
	make_edge();
	
	for(int i = 0; i < 210; i++) for(int j = 0; j < 210; j++) if(ed[i][j]) ans.add(i, j, ed[i][j]);
	
	printf("%d\n", ans.flow(0, 209));
	
	return 0;
}
