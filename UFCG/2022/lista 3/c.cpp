#include "bits/stdc++.h" //Two Small Strings
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
    string x, y;
    string abc = "abc";
    vector<string> ways;
    cin>>n>>x>>y;

    do{
    	string curr = "";
    	for(int i=0;i<n;++i)
    		curr += abc;
    	ways.pb(curr);

    	string separados = "";
    	for(char &c : abc){
    		for(int i=0;i<n;++i)
    			separados += c;    		
    	}

    	ways.pb(separados);
    }while(next_permutation(ALL(abc)));

    string ans = "";
    for(string &curr : ways)
    	if(curr.find(x) == string::npos && curr.find(y) == string::npos){
    		ans = curr;
    		break;
    	}

    if(!ans.empty())
    	cout<<"YES\n"<<ans<<"\n";
    else
    	cout<<"NO\n";
}