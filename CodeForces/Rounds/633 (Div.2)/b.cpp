#include <bits/stdc++.h>
using namespace std;

int main(){

	int t;
	scanf("%d", &t);
	
	for(; t > 0; t--){
		int n;
		scanf(" %d", &n);
		
		vector <int> l(n, 0);
		
		for(int i = 0; i < n; i++) scanf(" %d", &l[i]);
		
		sort(l.begin(), l.end());
		
		if(n % 2) printf("%d ", l[n / 2]);
		for(int i = n / 2 - 1, j = n / 2 + (n % 2); i >= 0; printf("%d %d ", l[i--], l[j++]));
		printf("\n");
	}
	
	return 0;
}
