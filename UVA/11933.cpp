#include <bits/stdc++.h> //(LogN)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;

const int N = 36;

int n;
string number,A,B;
vector<int> id;

void go(int x)
{
	A = "";
	for(int i=0;i<x;++i)
		A+="0";
	B = A;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	while(cin>>n && n)
	{
		number = "";
		while(n > 0)
		{
			if(n%2 == 1)
				number+="1";
			else
				number+="0";
			n/=2;
		}

		int qnt = 0;
		go(number.size());
		for(int i=0;i<number.size();++i)
		{
			if(number[i] == '1')
			{
				qnt++;
				if(qnt%2 == 1) A[i] = '1';
				else B[i] = '1';
			}
		}
		int u = 0,v = 0;
		int prod = 1;
		for(int i=0;i<number.size();++i)
		{
			if(A[i] == '1')
				u+=prod;
			if(B[i] == '1')
				v+=prod;
			prod*=2;
		}

		cout<<u<<" "<<v<<"\n";
	}
}