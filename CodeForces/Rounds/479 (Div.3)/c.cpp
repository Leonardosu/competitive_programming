#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	scanf("%d", &n);
	
	priority_queue <pair<int, int>> q;
	
	for(int i = 0; i < n; i++){
		int a, b;
		scanf(" %d %d", &a, &b);
		
		q.push({-a, -b});
	}
	
	int T = -q.top().second;
	for(pair <int, int> x = q.top(); !q.empty(); x = q.top()){
		q.pop();
		
		T = (-x.second >= T) ? -x.second : -x.first;
	}
	
	printf("%d\n", T);
		
	return 0;
}
