/*		
	1234 - Dancing Sentence
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;
string input;

void change()
{
	bool flag = true;
	for(int i = 0;i<input.size();++i)
		if(isalpha(input[i]))
		{
			if(flag)  { input[i] = toupper(input[i]); flag = false;}
			else	  { input[i] = tolower(input[i]); flag = true;}
		}	
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(getline(cin,input))
	{
		change();
		cout<<input<<"\n";
	}
}