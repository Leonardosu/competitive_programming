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

    vector<string> ini(3), fim(3);

    for(auto &s : ini)
    	cin>>s;
    for(auto &s : fim)
    	cin>>s;

    int diff = 0;
    for(int i=0;i<3;++i)
    	if(ini[i] != fim[i])
    		diff++;

    int moves = 0;
    
    if(diff == 2){
    	moves = 1;
    } else if(diff == 3){
    	moves = 2;
    }

  	if(moves == 1)
  		cout<<"No";
  	else
  		cout<<"Yes";
  	cout<<"\n";
}