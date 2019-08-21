/*	
	1241 - Fit or Dont Fit II
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

int a,b,t;
int tam_a,tam_b;
bool encaixa=true;
string number_a,number_b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin>>t;
	for(int i=1;i<=t;++i)
	{
		encaixa=true;
		cin>>number_a>>number_b;
		tam_a=number_a.size()-1; tam_b=number_b.size()-1;
		if(tam_b>tam_a) cout<<"nao encaixa\n";

		else
		{
			int cont_b=0;
			for(int j=tam_a-tam_b;j<=tam_a;++j)
			{
				if(number_b[cont_b]!=number_a[j]) {encaixa=false; break;}
				cont_b++;
			}

			if(!encaixa) cout<<"nao encaixa\n";
			else cout<<"encaixa\n";
		}
	
	}

	return 0;
}
