#include <bits/stdc++.h>
using namespace std;

struct trans{long long m[5][5] = {{1ll, 0ll, 0ll, 0ll, 0ll}, {1ll, 1ll, 0ll, 0ll, 0ll}, {0ll, 0ll, 0ll, 1ll, 0ll}, {0ll, 0ll, 0ll, 0ll, 1ll}, {1ll, 1ll, 1ll, 1ll, 1ll}};};

long long mod(long long x){
	while(x >= 1000000007ll) x = x % 1000000007ll + x / 1000000007ll;
	
	return x;
}

inline trans operator *(trans a, trans b){
	trans t;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++){
			t.m[i][j] = 0ll;
			for(int k = 0; k < 5; k++) t.m[i][j] = mod(t.m[i][j] + a.m[i][k] * b.m[k][j]);
		}
	}
	return t;
}

trans fpowt(long long x){
	
	trans t, ans;
	
	for(int i = 0, v = 0; (1ll << i) <= x; i++){
		if((1ll << i) & x){
			if(!v) {ans = t; v = 1;}
			else ans = ans * t;
		}
		t = t * t;
	}
	
	return ans;
}

long long fpow(long long n, long long t){
	
	long long ans;
	
	for(int i = 0, v = 0; (1ll << i) <= t; i++){
		if((1ll << i) & t){
			if(!v) {ans = n; v = 1;}
			else ans = ans * n % 1000000007ll;
		}
		n = n * n % 1000000007ll;
	}
	
	return ans;
}

int main(){
	
	long long n, f1, f2, f3, c;
	scanf("%I64d %I64d %I64d %I64d %I64d", &n, &f1, &f2, &f3, &c);
	
	trans t = fpowt(n - 3ll);
	
	printf("%I64d\n", (fpow(c, mod(t.m[4][0] * 2ll)) * fpow(f1, mod(t.m[4][2])) % 1000000007ll) * (fpow(f2, mod(t.m[4][3])) * fpow(f3, mod(t.m[4][4])) % 1000000007ll) % 1000000007ll);
	
	return 0;
}
