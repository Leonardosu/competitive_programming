#include <bits/stdc++.h> 
#define f first
#define s second
#define pb push_back
using namespace std;

int n,x,best,ans;
map<string,int> dic;
vector<string> aux;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	while(cin>>n && n)
	{		
		dic.clear();
		string A,B;

		for(int i=0;i<n;++i)
		{
			A = "";
			aux.clear();

			for(int j=0;j<5;++j)
			{
				cin>>B;
				aux.push_back(B);
			}

			sort(aux.begin(),aux.end());
			for(int j=0;j<5;++j)
				A+=aux[j];

			dic[A]++;
		}

		ans = best = 0;
		for(auto e : dic)	
			best = max(best,e.s);		
		
		for(auto e : dic)
			if(e.s == best)
				ans++;

		cout<<ans*best<<"\n";
	}
}