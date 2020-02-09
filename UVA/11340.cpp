#include <bits/stdc++.h> 
using namespace std;

char c;
int q,n,x;
map<char,int> dic;
string linha;
long long int total;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>q;
	while(q--)
	{
		dic.clear();
		total = 0;

		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>c>>x;
			dic[c] = x;
		}

		cin>>n;
		cin.ignore();
		for(int i=0;i<n;++i)
		{
			getline(cin,linha);
			for(int j=0;j<linha.size();++j)
				total+=dic[linha[j]];			
		}

		if(total%100 < 10)
			cout<<total/100<<".0"<<total%100<<"$\n";
		else
			cout<<total/100<<"."<<total%100<<"$\n";
	}
}