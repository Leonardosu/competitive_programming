#include <bits/stdc++.h>
using namespace std;

bool chess[9][9];
int queen[9];
int ans  = 0;

bool look(int pos,int x)
{
	if( !chess[pos][x] ) return false;

	for(int i=1;i<pos;++i)
		if(abs(i - pos) == abs(queen[i] - x) || queen[i] == x) return false;
	return true;
}


void solve(int pos)
{
	if(pos >= 9)
	{
		ans++;
		return;
	}

	for(int i=1;i<=8;++i)
	{
		if(look(pos,i))
		{
			queen[pos] = i;
			solve(pos+1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	char c;
	for(int i=1;i<=8;++i)
		for(int j=1;j<=8;++j)
		{
			cin>>c;
			if(c == '.') chess[i][j] = true;
			else chess[i][j] = false;
		}

	solve(1);
	cout<<ans<<"\n";
}