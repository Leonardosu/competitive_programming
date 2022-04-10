#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

int qnt[3];

int num(char c)
{
	if(c == 'R') return 0;
	if(c == 'P') return 1;
	return 2;
}

char letra(int x)
{
	if(x == 0) return 'R';
	if(x == 1) return 'P';
	return 'S';
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		qnt[0] = qnt[1] = qnt[2] = 0;
		for(char &c : s)
			qnt[num(c)]++;
			
		int best = 0;
		int ans;
		for(int i=0;i<3;++i)
		{
			if(qnt[i] > best)
				best = qnt[i],ans = i;
		}


		for(int i=0;i<s.size();++i) cout<<(letra((ans+1)%3));
		cout<<"\n";
	}
}