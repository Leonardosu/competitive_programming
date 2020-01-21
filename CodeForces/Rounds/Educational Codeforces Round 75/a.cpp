#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
 
using namespace std;
 
const int N = 300;
const int INF = 1e8;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
string input;
vector<char> resp;
set<char>save;
 
int t;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
	cin>>t;
	while(t--)	
	{
		cin>>input;
		
		resp.clear();
		save.clear();
 
		int quantidade = 0;
		char atual = input[0];
 
		for(int i=0;i<input.size();++i)
		{
			if(input[i] == atual)
				quantidade++;
			else
			{
				if(quantidade%2 == 1 && (save.find(atual) == save.end()))
					resp.push_back(atual),save.insert(atual);
 
				atual = input[i];
				quantidade = 1;				
			}
		}
 
		if(quantidade%2 == 1 && save.find(atual) == save.end())
			resp.push_back(atual);
		sort(all(resp));
 
		for(int i=0;i<resp.size();++i)
			cout<<resp[i];
 
		cout<<"\n";
	}
 
	
}