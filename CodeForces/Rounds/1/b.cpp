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

string columnRowToRowColumn(string &s) { //BC23
	int n = s.size();
	
	int row = 0, column = 0;
	int prefix = -1;
	for(int i=0;i<n;++i) {
		if(isdigit(s[i])) break;
		prefix++;
	}

	row = stoi(s.substr(prefix+1, n));
	for(int i=0;i<=prefix;++i) {
		column *= 26;
		column += s[i] - 'A' + 1;
	}
	
	string ans = "R" + to_string(row) + "C" + to_string(column);	
	return ans;
}

string rowColumnToColumnRow(string &s) {
	int n = s.size();
	
	int row = 0, column = 0;
	int prefix = -1;
	for(int i=1;i<n;++i) {
		if(isalpha(s[i])) break;
		prefix = i;
	}
	row = stoi(s.substr(1, prefix));
	column = stoi(s.substr(prefix+2, n));

	string ans = "";
	while(column) {
		int resto = (column%26 + 25)%26;
		ans += 'A' + resto;
		column -= resto;
		column /= 26;
	}
	reverse(ALL(ans));
	return ans + to_string(row);
}

void solve_task()
{
	string s;
	cin>>s;

	bool ligado = false;
	int digitos = 0;
	for(int i=0;i<(int)s.size();++i) {
		if(isalpha(s[i])) {
			ligado = false;
		} else {
			if(!ligado) digitos++;
			ligado = true;
		}
	}

	bool type1 = (digitos == 1 ? true : false);
	cout<<(type1 ? columnRowToRowColumn(s) : rowColumnToColumnRow(s))<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}