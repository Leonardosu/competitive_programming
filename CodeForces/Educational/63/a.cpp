#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 1;
const int INF = 1e9;
typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

string input;
int a,b;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>a;
	cin>>input;
	a = b = -1;

	for(int i=0;i<input.size()-1;++i)
	{
		if(input[i+1] < input[i])
		{
			a = i, b = i+1;
			break;
		}
	}
	if(b == -1) cout<<"NO\n";
	else cout<<"YES\n"<<a+1<<" "<<b+1<<"\n";
}