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

	int n;
	cin>>n; cin.ignore();
	string s;
	getline(cin, s);
	// cout<<s<<"\nuhu\n";
	int moves;
	cin>>moves;
	int lower = 1;
	string result;

	for(int i=0;i<moves;++i) {
		string ss;
		cin>>ss;

		
		if(ss == "CapsLock")
			lower = 1 - lower;
		else if(ss == "Backspace"){
			if(!result.empty())
				result.pop_back();
		}
		else if(ss == "Space")
			result += " ";
		else {
			if(!lower)
				result += toupper(ss[0]);
			else
				result += ss;
		}
		
	}

	// cout<<result<<" | "<<s<<"\n";
	cout<<(result == s ? "Correct" : "Incorrect")<<"\n"; 

}