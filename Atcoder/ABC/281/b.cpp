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

    string s;
    cin>>s;

    char a = s[0], b = s.back();
    bool valid = false;
    if(s.size() == 8 && isalpha(a) && isalpha(b)) {
    	valid = true;
    	for(int i=1;i<7;++i)
    		if(isalpha(s[i])) {
    			valid = false;
    			break;
    		}
    	
    	if(valid) {
    		string ss = s.substr(1,6);
    		int x = stoi(ss);
    		valid = (100000 <= x && x<= 999999);
    	}

    }

    cout<<(valid ? "Yes" : "No")<<"\n";
}