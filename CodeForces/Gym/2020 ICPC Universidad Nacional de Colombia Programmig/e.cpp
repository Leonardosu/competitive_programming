#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;


int query(int root)
{
    int d;
    cout<<root<<endl;
    cin>>d;
    return d;
}

int main()
{
	ios_base::sync_with_stdio(false); 


	int n,root = 1,dist = 0;
    cin>>n;
    dist = query(root);
    while(dist > 0)
    {
        int prox = query(root*2);
        if(dist < prox) root = root*2 + 1;
        else root*=2;
        if(dist == 1) 
        {
            cout<<"! "<<root<<endl;
            return 0;
        }
        dist--;
    }
    cout<<"! "<<root<<endl;
}