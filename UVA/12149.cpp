#include <bits/stdc++.h>
using namespace std;

int n,x;
int long long tamanho[110],atk;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	tamanho[1]=1;
	for(int i=2;i<=100;++i) {
		atk=i*i;
		tamanho[i]=atk+tamanho[i-1];
	}
	
	while(cin>>n && n) {
		cout<<tamanho[n]<<'\n';
	}

	return 0;
}
