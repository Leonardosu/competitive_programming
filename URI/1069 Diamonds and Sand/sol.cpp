/*	
	1069 - Diamonds and Sand
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

char mina[1010];
char x;
int Case,cont;

int main() // 1069 URI
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>Case;

	while(Case--)
	{
		cin>>mina;
		cont=0;
		
		if(strlen(mina)==0)
		{
			cout<<"1\n";
			continue;
		}

		stack<char> pilha;
		for(int i=0;i<strlen(mina);++i)
		{
			if(mina[i]=='<')
				pilha.push('<');

			if(mina[i]=='>' && !pilha.empty())
			{
				if(pilha.top()=='<')
				{
					pilha.pop();
					cont++;
				}
				
			}
		}

		cout<<cont<<'\n';
	}

	return 0;
}