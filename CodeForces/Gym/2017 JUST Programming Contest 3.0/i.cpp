#include <bits/stdc++.h> // AC
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define N 300
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;


int n,q,a,b;
string input;
vector<string> data;
int qnt[N][12];
int dp[N][N];

bool visited[N];

void clear()
{
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=10;++j)
			qnt[i][j] = 0;
		visited[i] = false;
	}

	data.clear();
}

bool match(int x,int y)
{
	int xx = 0;
	for(int i=0;i<10;++i)
		xx+=min(qnt[x][i],qnt[y][i]);
	if(xx == 17) return true;
	return false;
}


int solve(int pos)
{
	queue<ii> fila;

	fila.push(mp(pos,0));

	while(!fila.empty())
	{
		ii atual = fila.front();
		fila.pop();

		if(atual.f == b) return atual.s;
		visited[atual.f] = true;

		for(int i=1;i<=n;++i)
		{
			if(match(atual.f,i) && !visited[i])
				fila.push(mp(i,atual.s+1));
			
		}
	}

	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>q;
	while(q--)
	{
		cin>>n>>a>>b;

		clear();

		for(int i=1;i<=n;++i)
		{
			cin>>input;
			data.pb(input);
			for(int j=0;j<input.size();++j)
			{
				int xx = input[j] - '0';
				qnt[i][xx]++;
			}
		}

		cout<<solve(a)<<"\n";
	}

}