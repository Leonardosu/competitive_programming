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

void solve_task()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int qnt = 2, curr = 0;
	char last = '#';

	for(char campo : s) {
		if(campo != last) curr = 0;
		last = campo;
		curr++;

		cout<<qnt - curr<<" ";
		qnt++;
	}	

	cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T_T = 1;
    cin>>T_T;
    while(T_T--)
        solve_task();
}