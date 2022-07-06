#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int a, b;
	cin>>a>>b;
	string s;
	cin>>s;
	if(s.size() != a + b + 1) {
		cout<<"No\n";
		return 0;
	}

	bool ok =  true;
	int qnt = 0;
	for(char &c : s) {
		if(c == '-')
			qnt++;
		else if(!isdigit(c))
			ok = false;
	}

	if(ok && qnt == 1 && s[a] == '-') {
		cout<<"Yes\n";
	} else
		cout<<"No\n";
}