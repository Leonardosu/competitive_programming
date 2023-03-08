#include <stdio.h>
 
int main() {
    long long int a,b,x;
    while(scanf("%lld %lld",&a,&b) != EOF) {
    	x = a^b;
        printf("%lld\n",x);
    }
     
	return 0;
}
