/*	
	1235 - Inside Out
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;
string input,a,b;
int n;

void change()
{
	a=""; b="";
	for(int i = 0;i<input.size();++i)
	{
		if(i<input.size()/2)
			a+=input[i];
		else
			b+=input[i];
	}

	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	input = a + b;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	cin.ignore();
	for(int i = 0;i<n;++i)
	{
		getline(cin,input);
		change();
		cout<<input<<"\n";
	}
}