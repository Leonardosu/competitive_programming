/*
	MIRRORED SPOJ
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

string K;
char a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int A,B;
	A = 'b' + 'd';
	B = 'q' + 'p';

	cout<<"Ready\n";
	while(getline(cin,K))
	{
		if(K == "  ") break;
		a = K[0];
		b = K[1];
		if( (a=='b' || b=='b') && (int)a+b == A)
			cout<<"Mirrored pair\n";
		else if( (a=='p' || b=='p') && (int)a+b == B)
			cout<<"Mirrored pair\n";
		else
			cout<<"Ordinary pair\n";
	}
}