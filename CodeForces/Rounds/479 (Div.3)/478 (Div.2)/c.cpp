#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a, b, c, l[3];
	scanf("%lld %lld %lld", &a ,&b, &c);
	
	l[0] = a; l[1] = b; l[2] = c;
	sort(l, l + 3);
	
	a = l[2]; b = l[1]; c = l[0];
	
	printf("%lld", c + (b - c) / 3 * 2 + );
	
	return 0;
}
	
	
