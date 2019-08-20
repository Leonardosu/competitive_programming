/*	
	1024 - Encryption
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;
string input;
int n;

void cript()
{
	int size = input.size();
	for(int i = 0 ;i<size;++i) //passo 1
		if(isalpha(input[i])) input[i]+=3;

	reverse(input.begin(),input.end()); //passo 2

	for(int i = size/2;i<size;++i) //passo 3
		input[i]-=1;

	cout<<input<<"\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n;
	cin.ignore();

	for(int i=0;i<n;++i)
	{	
		getline(cin,input);
		cript();
	}
}