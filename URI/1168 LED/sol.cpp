/*		
	1168 - LED
	Leonardo Su
*/
#include <bits/stdc++.h>
using namespace std;

long long int sum;
int n;
string number;

void trade(char x)
{
	if(x=='1') sum+=2;
	else if(x=='7') sum+=3;
	else if(x=='4') sum+=4;
	else if(x=='8') sum+=7;
	else if(x=='2' || x=='3' || x=='5') sum+=5;
	else if(x=='0' || x=='6' || x=='9') sum+=6;
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	while(cin>>n)
	{
		for(int j=0;j<n;++j)
		{
			sum=0;
			cin>>number;
			for(int i=0;i<number.size();++i)
				trade(number[i]);
			cout<<sum<<" leds\n";		
		}
	
	}	

	return 0;
}
