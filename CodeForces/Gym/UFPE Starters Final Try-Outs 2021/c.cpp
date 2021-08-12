#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N,k,q,M;
string m,n;
// bool flag = true;

char get(int i,string &s)
{
	// string res = "";
	int res = 0;
	// i-k,i,i+k
	int pos;
	
	for(int id = (i-k); id <= i+k; ++id)
	{
		pos = id;

		if(pos < 0)
			pos += N;
		if(pos >= N)
			pos -= N;

		res <<=1;	
		res += s[pos] - '0';		
	}

	return m[res];
}

string solve(string &n)
{
	string ans = "";

	for(int i=0;i<n.size();++i)
	{
		ans += get(i,n);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>N>>k>>q;
	cin>>m>>n;

	reverse(ALL(m));

	while(q--)
		n = solve(n);		
	
	cout<<n<<"\n";
}
