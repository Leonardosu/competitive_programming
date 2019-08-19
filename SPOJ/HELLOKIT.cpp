/*
	HELLOKIT SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
string word,frase;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while(cin>>word && word!=".")
	{
		cin>>n; frase.clear();
		for(int i=0;i<n;++i)
			frase+=word;
		for(int i=0;i<word.size();++i)
		{			
			cout<<frase<<"\n";
			frase.erase(frase.begin());
			frase+=word[i];
		}
	}
}