#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;

const int N = 120;

bool visited[N][N];
char mapa[N][N];
int a,b,n,s;
int t;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n>>s;
		int need = s/n;
		int use = min(a,need);
		int atual = use*n;
		if(atual + b >= s)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}