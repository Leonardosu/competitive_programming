#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;
const int N = 200010;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

int n,x;
int ans[N];
vector<int> v;
multiset<int> save;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=1;i<=n;++i)
		cin>>ans[i];

	for(int i=1;i<=n;++i)
	{
		cin>>x;
		save.insert(x);
	}

	for(int i=1;i<=n;++i)
	{
		int valor = ans[i];
		auto it = save.lower_bound(n-valor);
		if(it == save.end()) it = save.begin();
		cout<<(ans[i] + *it)%n<<" ";
		save.erase(it);
	}
	
	cout<<"\n";
}