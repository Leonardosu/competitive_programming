#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);

    vector<int> v(4);
    for(int i=0;i<4;++i)
    	cin>>v[i];
    

 	sort(v.begin(),v.end());
 	cout<<abs(v[3] + v[0] - (v[2] + v[1]))<<"\n";

    return 0;
}