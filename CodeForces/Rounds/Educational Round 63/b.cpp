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

string number;
int qnt,moves;
vector<int> pos;
bool possible = true;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>moves;
	qnt = 0;
	moves -= 11;

	cin>>number;
	for(int i=0;i<number.size()-10;++i)	
		if(number[i] == '8')
		{
			qnt++;
			pos.pb(i);
		}

	if(moves/2 >= qnt) possible = false;

	if(possible) cout<<"YES\n";
	else cout<<"NO\n";

}