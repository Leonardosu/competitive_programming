#include <bits/stdc++.h> //UVA 10215 - The Largest/Smallest Box
#define EPS 1e-8		// Precision
using namespace std;

double l,w,h1,h2,h3,h4;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	while(cin>>l>>w)
	{
		h1=(w+l-sqrt(pow(w+l,2)-3*w*l))/6;
		h2=(w+l+sqrt(pow(w+l,2)-3*w*l))/6;

		h3=min(w,l)/2 + EPS;

		cout<<fixed<<setprecision(3);

		cout<<h1<<' '<<h4<<' '<<min(h2,h3)<<"\n";
	}

	return 0;
}