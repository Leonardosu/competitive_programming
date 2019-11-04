#include <bits/stdc++.h> // UVA - 489
using namespace std;

bool palavra[30],mark[30];
int t,need,moves;

void reset()
{
	for(int i=0;i<=27;++i)
		palavra[i] = mark[i] = false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string word,guess;

	while(cin>>t && t != -1)
	{
		reset(); moves = 0,need = 0;

		cin>>word>>guess;
		for(auto e : word)
		{
			int x = e - 'a';
			if(!palavra[x])
				need++;
			palavra[x] = true;
		}
		
		for(auto e : guess)
		{
			int x = (e - 'a');

			if(mark[x])
				continue;

			if(palavra[x])
			{
				need--;
				if(need == 0)
					break;
			}
			else
				moves++;	
			mark[x] = true;
		}

		cout<<"Round "<<t<<"\n";
		if(need == 0 && moves < 7)
			cout<<"You win.\n";
		else if(moves < 7 && need > 0)
			cout<<"You chickened out.\n";
		else
			cout<<"You lose.\n";

	}

}