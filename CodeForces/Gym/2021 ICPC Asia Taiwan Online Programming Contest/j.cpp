#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a,b;
	cin>>a>>b;
	
	int x=0;
	int y=0;
	
	//bool pode=true;
	
	int pot=1;
	
	for (int i=(int)a.size()-1; i>=0; i--){
		if (a[i]-'0'>=0 and a[i]-'0'<=9){
			x+=pot*(a[i]-'0');
		}
		else{
			cout<<"NaN"<<endl;
			return 0;
		}
		pot*=10;
	}
	
	pot=1;
	
	for (int i=(int)b.size()-1; i>=0; i--){
		if (b[i]-'0'>=0 and b[i]-'0'<=9){
			y+=pot*(b[i]-'0');
		}
		else{
			cout<<"NaN"<<endl;
			return 0;
		}
		pot*=10;
	}
	
	cout<<x-y<<endl;
	
}
