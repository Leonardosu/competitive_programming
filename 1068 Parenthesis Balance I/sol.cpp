/*
	1068 - Parenthesis Balance I
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

char mina[10010];
char x;
int Case,cont;

int main() // 1069 URI
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while(cin>>mina)
	{
		stack<char> pilha;
		for(int i=0;i<strlen(mina);++i)
		{
			if(mina[i]=='(')
				pilha.push('(');

			if(mina[i]==')')
			{
				if(!pilha.empty())
					if(pilha.top()=='(' )
					{
						pilha.pop();
						continue;
					}
				
				pilha.push(')');
			}

		}

		if(!pilha.empty())
			cout<<"incorrect\n";
		else
			cout<<"correct\n";
	}

	return 0;
}