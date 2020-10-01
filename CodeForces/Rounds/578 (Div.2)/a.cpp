#include <bits/stdc++.h>
using namespace std;

int room[11];
char t;
int n;

void enter(int x)
{
	if(x == 0)
	{
		for(int i=0;i<10;++i)
			if(room[i] == 0)
			{
				room[i] = 1;
				break;
			}
	}
	else 
	{
		for(int i=9;i>=0;--i)
			if(room[i] == 0)
			{
				room[i] = 1;
				break;
			}
		}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin>>n; cin.ignore();
	string input;
	cin>>input;
	for(int i=0;i<input.size();++i)
	{
		t = input[i];
		if(t == 'L')
			enter(0);
		else if(t == 'R')
			enter(1);
		else
			room[(t-'0')] = 0;					
	}

	for(int i=0;i<=9;++i)
		cout<<room[i];
	cout<<"\n";
}