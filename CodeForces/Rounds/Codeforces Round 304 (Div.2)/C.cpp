#include <bits/stdc++.h>
using namespace std;

int n,games = 0;
int a,b,x;
queue<int> p1,p2;
string loop;

set< pair<string,string> > save; // trick :) salva os status como strings e procura no set 

bool looping(queue<int> xx,queue<int> yy)
{
	string s = ""; string ss = "";

	while(!xx.empty())
	{
		ss += xx.front() + '0';
		xx.pop();
	}
	
	while(!yy.empty())
	{
		s += yy.front() + '0';
		yy.pop();
	}

	pair<string,string> now = make_pair(ss,s);
	if(save.find(now) != save.end()) return true;

	else
		save.insert(now);
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>n;

	cin>>a;
	for(int i=0;i<a;++i)
	{
		cin>>x; p1.push(x);
	}

	cin>>b;
	for(int i=0;i<b;++i)
	{
		cin>>x; p2.push(x);
	}

	bool winner ;

	while(true)
	{

		if(p1.empty())
		{
			winner = 1;
			break;
		}

		else if(p2.empty())
		{
			winner = 0;
			break;
		}

		games++;

		if(looping(p1,p2))
		{
			cout<<"-1\n";
			return 0;
		}

		int card1 = p1.front(); p1.pop();
		int card2 = p2.front(); p2.pop();

		if(card1>card2)
			p1.push(card2),p1.push(card1);
		else
			p2.push(card1),p2.push(card2);
	}

	cout<<games<<" "<<winner+1<<"\n";
}