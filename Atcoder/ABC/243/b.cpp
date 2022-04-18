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
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    map<int,int> A,B;
    int n;
    cin>>n;
    vector<int> a(n), b(n);
    for(int &x : a)
    {
    	cin>>x;
    	A[x]++;
    }
    for(int &x : b)
    {
    	cin>>x;
    	B[x]++;
    }
    int q = 0, w = 0;
    for(int i=0;i<n;++i)
    {
    	if(a[i] == b[i])
    		q++, A[a[i]]--, B[a[i]]--;
    }
    for(auto &[x, qnt] : A)
    {
    	w += min(A[x], B[x]);
    }
    cout<<q<<"\n";
    cout<<w<<"\n";
}
