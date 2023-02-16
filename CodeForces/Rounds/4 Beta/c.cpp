#include <bits/stdc++.h>
using namespace std;

map<string,int> dic;
string s;
int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n;
	while(n--) {
		cin>>s;
		if(dic[s] == 0) cout<<"OK\n";
		else cout<<s<<dic[s]<<"\n";
		dic[s]++;
	}
}