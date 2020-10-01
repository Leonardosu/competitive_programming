#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int maxn = 1e5 + 7;
const int S = 26;

string s;
int ans[maxn],n;

struct node
{
	node *prox[S];
    int qnt;
	node()
	{
		for(int i = 0; i < S; i++) prox[i] = NULL;
        qnt = 0;
	}
};



void Insert(node *root, string s)
{
	for(int i = 0; i < s.size(); i++)
	{
		int id = s[i] - 'a';

		if(!root->prox[id]) root->prox[id] = new node();

		root = root->prox[id];
        root->qnt++;
        ans[i+1] = max(ans[i+1],root->qnt);
	}
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t,q;
    cin>>t;
    for(int zz=0;zz<t;++zz)
    {
        cin>>n>>q;    
        memset(ans,0,sizeof(ans));

        string s;        
        node *root = new node();

        for(int i=0;i<n;++i)
        {
            cin>>s;
            reverse(all(s));
            Insert(root,s);
        }         
        
        for(int i=0;i<q;++i)
        {
            int x;
            cin>>x;
            cout<<ans[x]<<"\n";
        }

        
    }
		
}