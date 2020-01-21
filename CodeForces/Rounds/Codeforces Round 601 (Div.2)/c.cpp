#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
const int N = 1e5 + 100;

int a,b,c;
int qnt[N],ans[N],n;
bool mark[N];

vector<ii> aux[N];

bool check(int x,int y,int a,int b)
{
	if(x == a && y != b) return true;
	return false;
}

int solve(vector<ii> x, int a, int b)
{
	for(int i=0;i<x.size();++i)
	{
		ii y = x[i];
		if(check(y.f, y.s, a, b)) return y.s;
		if(check(y.s, y.f, a, b)) return y.f;
	}

	return n;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	int start;

	for(int i=0;i<n-2;i++)
	{
		cin>>a>>b>>c;

		aux[a].pb(mp(b, c));	aux[b].pb(mp(a, c));	aux[c].pb(mp(a, b));
		qnt[a]++;	qnt[b]++;	qnt[c]++;
	}

	for(int i = 1; i <= N; i++)
		if(qnt[i] == 1)
		{
			start = i;
			break;
		}

	ans[1] = start;
	ans[2] = aux[start][0].f;
	ans[3] = aux[start][0].s;

	if(qnt[ans[2]] > qnt[ans[3]]) 
		swap(ans[2], ans[3]);

	mark[ans[1]] = mark[ans[2]] = mark[ans[3]] = true;

	for(int i=4;i<=n;i++)
	{
		vector<ii> x;
		int id = ans[i-2];

		for(int jj=0;jj<aux[id].size();++jj)
			x.pb(aux[id][jj]);
		
		ans[i] = solve(x, ans[i - 1], ans[i - 3]);
	}
	
	for(int i=1;i<=n;++i)
		cout<<ans[i]<< " ";

	cout<<"\n";

	return 0;
}