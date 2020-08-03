#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 200010;
const long long int INF = 1e9;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int ll;

vector< vector<int> > matrix;
ll cnt[N];
int n,m,x;
ll movimentos;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	matrix.resize(n);

	for(int i=0;i<n;++i)
	{
		matrix[i].resize(m);
		for(int j=0;j<m;++j)
		{			
			cin>>matrix[i][j];
			matrix[i][j] --;			
		}
	}

	movimentos = 0;
	for(int coluna = 0;coluna<m;++coluna)
	{
		ll best = n;
		for(int i=0;i<n;++i) cnt[i] = 0;

		for(int i=0;i<n;++i)
		{
			if(matrix[i][coluna]%m != coluna || matrix[i][coluna] > (n*m-1) + coluna) continue;
			int val = (matrix[i][coluna] - coluna)/m;
			int shitf = (i - val + n)%n;
			cnt[shitf]++;
		}
		for(int i=0;i<n;++i)		
			best = min(n - cnt[i] + i,best);
		movimentos+=best;
	}
	cout<<movimentos<<"\n";
}