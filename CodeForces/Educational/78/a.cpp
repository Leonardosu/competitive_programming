#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define debug(x) cout<<"###\n"<<x<<"###\n";
using namespace std;


const int N = 1;
const int INF = 1e9;
typedef long long int ll;

vector<char> aux,p;
string A,B;
int n;

bool comp(vector<char> a , vector<char> b)
{

	for(int i=0;i<a.size();++i)
		if(a[i] != b[i]) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);

	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>A>>B;
		aux.clear(); p.clear();

		for(int i=0;i<A.size();++i)
			p.pb(A[i]);

		sort(all(p));
		bool possible = false;

		if(A.size() <= B.size())
		{

			for(int i=0;i<B.size() - A.size() + 1;++i)
			{
				aux.clear();
				for(int j = 0;j<A.size();++j)
					aux.pb(B[j+i]);

				sort(all(aux));
				if(comp(p,aux))
				{
					possible = true;
					break;
				}
			}			
		}

		if(possible) cout<<"YES\n";
		else cout<<"NO\n";
	}

}