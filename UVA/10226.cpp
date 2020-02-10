#include <bits/stdc++.h> 
#define f first
#define s second
using namespace std;


int q,t,cnt;
string input;
map<string,int> dic;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>q;
	cin.ignore();
	cnt = 0;

	getline(cin,input);
	while(q--)	
	{		
		while(getline(cin,input) && !input.empty())
		{
			dic[input]++;
			cnt++;
		}

		cout<<fixed<<setprecision(4);

		for(auto e : dic)
			cout<<e.f<<" "<< (100.0*double(e.s))/cnt<<"\n";

		if(q)
			cout<<"\n";
		cnt = 0;
		dic.clear();
	}
	return 0;
}