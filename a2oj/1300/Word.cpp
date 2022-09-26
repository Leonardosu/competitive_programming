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

    int up = 0, lower = 0;

    string s;
    cin>>s;
    for(char &c : s) {
    	if(islower(c))
    		lower++;
    	else
    		up++;
    }

    if(up > lower)
    	transform(s.begin(), s.end(),s.begin(), ::toupper);
    else
    	transform(s.begin(), s.end(),s.begin(), ::tolower);
    cout<<s<<"\n";
}