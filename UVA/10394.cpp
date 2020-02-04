#include <bits/stdc++.h>
using namespace std;
const int N = 20000010;

bool primo[N];
int twin[N],s;

void init()
{
	int limit = sqrt(N);
	for(int i=2;i<N;++i) primo[i] = true;

	primo[0] = primo[1] = false;
	for(int i=4;i<N;i+=2)
		primo[i] = false;

	for(int i=3;i<=limit+1;++i)
		if(primo[i])
		{
			for(int j=2*i;j<N;j+=i)
				primo[j] = false;
		}

	int cnt = 1;
	for(int i=3;i<N;++i)
		if(primo[i] && primo[i+2])
			twin[cnt] = i,cnt++;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	init();
	while(cin>>s)
		 cout<<"("<<twin[s]<<", "<<twin[s] + 2<<")\n";		
}