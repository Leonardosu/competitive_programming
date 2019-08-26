#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;

int t,n,ans;

int tipo(string s)
{
	string x = "";
	string a = "kitchen";
	string b = "living";

	if(s[0] == 'b' && s[1] == 'e' && s[2] == 'd') return 1;

	x = "";
	for(int i=0;i<s.size() && i<7;++i)
		x+=s[i];
	if(x == a) return 2;
	
	x = "";	
	for(int i=0;i<s.size() && i<6;++i)
		x+=s[i];
	if(x == b) return 3;

}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	while(t--)
	{
		int bed = 0;
		int kitchen = 0;
		int living = 0;

		string input;

		cin>>n; cin.ignore();

		for(int i=0;i<n;++i)
		{
			cin>>input;
			if(tipo(input) == 1)
				bed++;
				// bed.insert(input);
			if(tipo(input) == 2)
				kitchen++;
				// kitchen.insert(input);
			if(tipo(input) == 3)
				living++;
				// living.insert(input);
		}
		ans = min(living,kitchen);
		ans = min(ans,bed/2);
		cout<<ans<<"\n";
		// cout<<"#debug:"<<bed<<" "<<kitchen<<" "<<living<<"\n";
	}

}