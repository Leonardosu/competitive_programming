/*
	1022 - TDA Rational
	Leonardo Su
*/
#include <bits/stdc++.h>
#define MAXN 20
#define F first
#define S second
using namespace std;
typedef pair<int,int> ii;


int t,a,b,c,d;
char op,lixo[2];
int Cima,baixo;

int mdc(int a,int b)
{
	if(b==0) return a;
	return mdc(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		cin>>a>>lixo>>b>>op; //A/B
		cin>>c>>lixo>>d;	// C/D

		if(op=='+')	{	Cima=a*d+b*c; baixo=b*d;	}
		if(op=='-') {	Cima=a*d-b*c; baixo=b*d;	}
		if(op=='*') { 	Cima=a*c; baixo=b*d;	}
		if(op=='/') {Cima=a*d; baixo= b*c; }

		if(Cima==0)
		cout<<"/"<<baixo<<" = ";
		else 
		cout<<Cima<<'/'<<baixo<<" = ";

		int divi=mdc(Cima,baixo);
		if(divi!= 1) {Cima/=divi; baixo/=divi;}
		if(Cima<0 && baixo<0) {Cima*=-1; baixo*=-1;}
		if(baixo<0 && Cima>0) {Cima*=-1; baixo*=-1;}
		if(Cima==0)
		cout<<"/"<<baixo<<'\n';
		else 
		cout<<Cima<<"/"<<baixo<<'\n';
	}	
	
    return 0;
}
