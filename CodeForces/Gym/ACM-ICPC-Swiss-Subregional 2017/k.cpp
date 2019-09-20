#include <bits/stdc++.h>
#define f first
#define s seccond
#define pb pus_back
#define mp make_pair
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
string input;
string a = "ACM";
int j = 0;
 
int main()
{
	cin>>input; bool flag = false;
 
	if(input.size() <3 ) flag = false;
	
	else
	{
		for(int i=0;i<input.size()-2;++i)
		{
			if(input[i] == a[0] && input[i+1] == a[1] && input[i+2] == a[2])
			{
				flag = true;
				break;
			}
		}		
	}
 
	if(flag)
		cout<<"Fun!\n";
	else
		cout<<"boring...\n";
}