#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;
const int N = 100000;
const int INF = 1e9;

typedef long long int ll;
typedef pair<int,int> ii;

string number;


int f(int x)
{
	int qnt = 0;
	set<int> save;
	save.insert(x);
	while(x > 0)
	{
		
		x+=1;
		while(x%10 == 0)
				x/=10;
			
		if(save.find(x) != save.end())
			break;
		save.insert(x);
	}

	return save.size();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;
	cout<<f(n)<<"\n";

}