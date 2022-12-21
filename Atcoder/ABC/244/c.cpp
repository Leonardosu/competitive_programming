#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define sz(x) (int)(x).size()
#define ALL(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main()
{
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin>>n;

	bool visited[2*n + 20]; memset(visited,false,sizeof visited);
	int id = 1;
	int limit = 2*n + 1;
	for(int i=0;i<=n;++i) {

		while(id<=limit && visited[id])
			id++;

		visited[id] = true;
		cout<<id<<endl;

		int resp;
		cin>>resp;
		if(resp == 0) break;
		visited[resp] = true;
	}

}