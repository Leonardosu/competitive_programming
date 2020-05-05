#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

string input;
string ans;
int cnt[30];
int middle,n;
bool impar = false,ok = true;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin>>input; n = input.size();
	for(int i=0;i<n;++i)
		cnt[input[i] - 'A']++;
	for(int i=0;i<27;i++)
		if(cnt[i]%2)
		{
			if(!impar) impar = true,middle = i;
			else
			{
				ok = false;
				break;
			}
		}
	if( (n%2 == 0 && impar) || !ok)
	{
		cout<<"NO SOLUTION\n";
		return 0;
	}

	string ini = "",fim = "";

	for(int i=0;i<27;i++)
		while(cnt[i] >= 2)
		{
			ini += i + 'A';
			cnt[i]-=2;
		}

	fim = ini;
	reverse(fim.begin(),fim.end());
	
	for(int i=0;i<27;++i)
		if(cnt[i])
		{			
			ini+=i+'A';
			break;
		}

	cout<<ini<<fim<<"\n";
}