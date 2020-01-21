#include <bits/stdc++.h> //Greedy O(N*LogN)
using namespace std;
typedef long long int ll;

ll sum,cost;
int n,x;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	while(cin>>n && n)
	{
		cost = sum = 0;
		priority_queue<int, vector<int> , greater<int> > fila;

		for(int i=0;i<n;++i)
		{
			cin>>x;
			fila.push(x);
		}

		sum = 0;
		cost = 0;
		while(!fila.empty())
		{
			int a = fila.top();
			fila.pop();
			if(fila.empty())
				break;
			
			int b = fila.top(); fila.pop();
			sum = a + b;
			cost+=sum;
			fila.push(sum);
		}

		cout<<cost<<"\n";
	}
}