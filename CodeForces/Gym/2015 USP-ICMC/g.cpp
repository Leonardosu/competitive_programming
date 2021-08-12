#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string ss;
	cin>>ss;
	bool negacao = false;

	for(char &c: ss)
	{

		if(c == '[' || c == ']')
		{
			negacao = !negacao;
			c = (c == '[') ?  '(' : ')';			
		}

		else if(c == '(' || c == ')')
			continue;
		else if(negacao)
		{
			if(c == '+') c = '*';
			else if(c == '*') c = '+';
			else
			{
				// cout<<c<<" # "<<tolower(c)<<"\n";
				if(tolower(c) == c) 
					c = toupper(c);
				else
					c = tolower(c);
			}
		}

	}
	cout<<ss<<"\n";
}
