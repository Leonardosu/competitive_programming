#include <bits/stdc++.h>
#define N 5000010
using namespace std;

typedef long long int ll;
ll prefix[N],qnt[N];
int spf[N],a,b,n;
 
void crivo() //menor fator primo // small prime factor
{ 
    spf[1] = 1; 
    for (int i=2; i<N; i++) 
        spf[i] = i; 
  
    for (int i=4; i<N; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<N; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j) 
                	spf[j] = i; 
        } 
    } 
} 
 
int quantidade(int x) //quantidade de divisores primos 
{ 
    int xx = 0;
    while (x != 1) 
    { 
        xx ++;
        x /= spf[x]; 
    }
    return xx; 
}
 
void init()
{
	for(int i=1;i<N;++i) qnt[i] = prefix[i] = 0;
 
	for(int i=2;i<N;++i)
		qnt[i] = quantidade(i);
 
	prefix[1] = 0;
	for(int i=2;i<N;++i)
		prefix[i] = prefix[i-1] + qnt[i];
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
 
	crivo();
	init();
 
	cin>>n;	
	while(n--)
	{
		cin>>a>>b;
		cout<<prefix[a] - prefix[b]<<"\n";
	}
}