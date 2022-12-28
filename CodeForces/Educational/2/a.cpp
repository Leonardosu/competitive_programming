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

bool isInteger(string s) {
	if(s.empty()) return false;
	for(char &c : s) 
		if(!isdigit(c)) 
			return false;
	return true;
}

bool isLeadingZero(string s) {
	return (s[0] == '0' && s.size() > 1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string s, current;
    cin>>s;

    vector<string> a, b;
    for(char &c : s) {
    	if(c == ';' || c == ',') {
			if (isInteger(current) && !isLeadingZero(current))
				a.pb(current);
			else
				b.pb(current);

			current.clear();
    	} else {
    		current.pb(c);
    	}
    }

     			
	if (isInteger(current) && !isLeadingZero(current))
		a.pb(current);
	else
		b.pb(current);

	// cout<<a.size()<<" and "<<b.size()<<"\n";
	string dash = "-\n";
	if(a.empty()) {
		cout<<dash;
	} else {
		cout<<"\"";
		for(int i=0;i<(int)a.size();++i) {
			if(i) cout<<",";
			cout<<a[i];
		} cout<<"\"\n";
	}

	if(b.empty()) {
		cout<<dash;
	} else {
		cout<<"\"";
		for(int i=0;i<(int)b.size();++i) {
			if(i) cout<<",";
			cout<<b[i];
		} cout<<"\"\n";
	}
}