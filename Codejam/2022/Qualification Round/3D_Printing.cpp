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

struct Printer{
	vector<int> color;
};

void solve_task()
{
	vector<Printer> printers(3);
	for(auto &printer : printers)
	{
		printer.color.resize(4);
		for(int j=0;j<4;++j)
			cin>>printer.color[j];
	}

	int total = 0;
	int need = 1e6;
	vector<int> colors(4);
	for(int j=0;j<4;++j)
	{
		int menor = 1e9;
		for(auto &printer : printers)
			menor = min(menor, printer.color[j]);
		if(total + menor >= need)
			menor -= (total + menor - need);
		total += menor;
		colors[j] = menor;
	}

	if(total == need)
		cout<<colors[0]<<" "<<colors[1]<<" "<<colors[2]<<" "<<colors[3]<<"\n";
	else
		cout<<"IMPOSSIBLE\n";
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T_T = 1;
	cin>>T_T;
	for(int TTT=1;TTT<=T_T;++TTT)
	{
		cout<<"Case #"<<TTT<<": ";
		solve_task();
	}
}