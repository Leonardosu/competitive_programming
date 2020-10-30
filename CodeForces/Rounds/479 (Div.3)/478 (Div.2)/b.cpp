#include <bits/stdc++.h>
using namespace std;

int main(){
	
	long long n, m;
	scanf("%lld %lld", &n, &m);
	
	printf("%lld %lld\n", ((n / m + (n % m != 0)) * (n / m) / 2 * (n % m) + (n / m) * (n / m - 1) / 2 * (m - (n % m))), ((n - m + 1) * (n - m) / 2));
}
