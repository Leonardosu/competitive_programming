#include "bits/stdc++.h" //Longest Regular Bracket Sequence
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

string s;
int qwe = 0;

int solve1()
{
	stack<int> open;
	open.push(-1);
	int best = 0;
	for(int i=0;i<s.size();++i)
	{
		if(s[i] == '(')
			open.push(i);
		else
		{
			if(!open.empty())
				open.pop();

			if(!open.empty())
			{
				if(i - open.top() > best)
				{
					// cout<<open.top()<<" to "<<i<<"\n";
					qwe = 0;
				}

				best = max(best, i - open.top());
				if(best == i - open.top())
					qwe++;
			}
			else
				open.push(i);
		}
	}
	return best;
}

int solve2()
{
	return qwe;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s;

	int longest = solve1();
	int ways = solve2();

	if(longest == 0)
		ways = 1;

	cout<<longest<<" "<<ways<<"\n";
}