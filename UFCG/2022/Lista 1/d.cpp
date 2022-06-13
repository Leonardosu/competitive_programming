#include "bits/stdc++.h" //Tic-tac-toe
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Player
{
	char id;
	int moves = 0;
	Player(){}
	Player(char id_) : id(id_) {}
};

Player p1 = Player('X'), p2 = Player('0');

int n = 3, emptyCells = 0;
char grid[4][4];

bool won(Player player)
{
	for(int i=0;i<n;++i)
	{
		int qntRow = 0, qntColumn = 0;
		for(int j=0;j<n;++j)
		{
			qntRow += (grid[i][j] == player.id);
			qntColumn += (grid[j][i] == player.id);
		}

		if(qntRow == 3 || qntColumn == 3)
			return true;
	}

	int qntD1 = 0, qntD2 = 0;
	for(int i=0;i<n;++i)
	{
		qntD1 += (grid[i][i] == player.id);
		qntD2 += (grid[n-i-1][i] == player.id);		
	}

	return (qntD1 == 3) || (qntD2 == 3);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			cin>>grid[i][j];

			if(grid[i][j] == p1.id)
				p1.moves++;
			else if(grid[i][j] == p2.id)
				p2.moves++;
		}

	bool won1 = won(p1);
	bool won2 = won(p2);

	if(!(p1.moves == p2.moves || p1.moves == p2.moves + 1) || (won1 && won2) || 
		(won1 && p1.moves == p2.moves) || (won2 && p1.moves > p2.moves))
		cout<<"illegal";
	else if(won(p1))
		cout<<"the first player won";
	else if(won(p2))
		cout<<"the second player won";
	else if(p1.moves + p2.moves == n*n)
		cout<<"draw";
	else
		cout<<(p1.moves == p2.moves ? "first" : "second");

	cout<<"\n";
}