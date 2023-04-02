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

int days(string s){
	 int res = stoi(s.substr(0, 4)) * 365;
	 res += stoi(s.substr(5,2)) * 30;
	 res += stoi(s.substr(8,2));
	 return res;
}

//2019/04/30
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s;
    cin>>s;
    if(days(s) <= days("2019/04/30")) {
    	cout<<"Heisei\n";
    } else 
    	cout<<"TBD\n";
}