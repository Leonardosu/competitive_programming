/*
	NAJPF - Pattern Find SPOJ
	Leonardo Su
	Complexty O(|A|+|B|) with KMP Algorithm
*/
#include<bits/stdc++.h> 
#define N 3000100
using namespace std;

int prefix[N];

void kmp(string a,string b)
{
	string s = a + "#" + b;
	int n = s.size();
	prefix[0] = 0;
	int j = 0;

	for(int i = 1;i<n;++i)
	{
		while(j > 0 && (s[j] != s[i]))
			j = prefix[j-1];

		if(s[j] == s[i])
			prefix[i] = j + 1,j++;
	}
}

void reset()
{
	for(int i=0;i<N;++i) prefix[i] = 0;
}

int n,t;
vector<int>ans;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin>>t;
	string x,y,xx;
	bool flag = false;
	while(t--)
	{
		if(flag && t>=0) cout<<"\n\n";
		flag = true;

		cin>>x>>y;	
		reset(); ans.clear();
		int l = y.size() , r = x.size();

		kmp(y,x); 

		for(int i=0;i<l+r+1;i++)
		{
			if(prefix[i] == l)
				ans.push_back(i-l);
		}

		if(ans.size() != 0)
		{
			cout<<ans.size()<<"\n";
			for(int i=0;i<ans.size();++i)
				cout<<ans[i] - l + 1<<" ";
		}
		else cout<<"Not Found";
	}
}