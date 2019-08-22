/*				
	1768 - Christmas Tree
	Leonardo Su 
	8/1/19 11:06:25 AM
*/
#include <bits/stdc++.h>
using namespace std;

int n;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
 	while(cin>>n)
	{
		int D = (n-1)/2;
		string s = "*";

	    for(int z=0;z<=D;++z)
	    {	    	
	        for(int i=0;i<D-z;++i)
	            cout<<" ";
            cout<<s<<"\n";
            s+="**";
	    }
        for(int i=0;i<D;++i)
            cout<<" ";
        cout<<"*\n";
        for(int i=0;i<D-1;++i)
            cout<<" ";
        cout<<"***\n\n";
	}
}