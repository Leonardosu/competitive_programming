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

int n,x,y, dir;
string moves;

bool canReach(vector<int> &elements, int start, int target) {
	map<int,bool> dp, temp;

	dp[start] = true;
	for(int &x : elements) {
		temp = dp;
		dp.clear();
		for(auto &[y, can] : temp) {
			dp[y-x] = dp[y+x] = true;
		}
	}

	return dp[target];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin>>moves;
	cin>>x>>y;
	vector<int> elements[2];

	bool first = true;
	int dir = 0, curr = 0;
	int xStart = 0, yStart = 0;
	for(char &c : moves) {
		if(c == 'T') {			
			if(first && curr){
				xStart = curr;
			}
			else if(curr) 
				elements[dir].pb(curr);				
			
			dir = 1 - dir;
			curr = 0;
			first = false;
		} else {
			curr++;
		}
	}

	if(first)
		xStart = curr;
	else
		elements[dir].pb(curr);

	cout<<(canReach(elements[0], xStart, x) && canReach(elements[1], yStart, y) ? "Yes" : "No")<<"\n";
}