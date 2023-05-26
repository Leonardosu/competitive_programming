#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<int> kids;
int n;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		kids.pb(-x);
	}

	sort(all(kids));
	vector<int> ans;

	vector<int> esquerda,direta;
	bool flag = false;

	if(n%2 == 1)
		flag = true;
	else
		direta.pb(kids[0]);

	for(int i=1;i<n;++i)
	{
		if(i&1) 
			esquerda.pb(kids[i]);
		else 
			direta.pb(kids[i]);
	}

	reverse(all(esquerda));

	for(int &x : esquerda)
		cout<<-x<<" ";
	if(flag) cout<<-kids[0]<<" ";
	for(int &x : direta)
		cout<<-x<<" ";

	cout<<"\n";
}