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

const int N = 1e6 + 7;
int d[N];
 
int bs(int l, int r, int v) {
	while(r-l>1) {
		int m=(r+l)/2;
		if(d[m]<=v) l=m;
		else r=m;
	}
	return (d[r]<=v ? r : l);
}
 
int bs2(int l, int r, int v) {
	while(r-l>1) {
		int m=(r+l)/2;
		if(d[m]<=v) r=m;
		else l=m;
	}
	return (d[l]<=v ? l : r);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s;
	int n, a, b, T;

	cin>>n>>a>>b>>T>>s;
    s = s + s;

    d[n] = 1 + (s[n] == 'w')*b;
    if(d[n]>T) {
    	cout<<"0\n";
    	return 0;
    }

    int res = 1;
    int l = 1, r = n;

    for(int i=n+1;i<2*n;++i) {
    	d[i] = d[i-1] + (1 + a + (s[i]=='w')*b);
    	if(d[i]>T) 
    		break;
    	res = max(res,i-n+1);
    	r = i;
    }

    for(int i=n-1;i>0;--i) {
    	d[i] = d[i+1] + (1 + a + (s[i]=='w')*b);
    	if(d[i]>T) 
    		break;
    	res = max(n-i+1,res);
    	l = i;
    }

    for(int i=l; i<n; i++)
    	if(d[i] + a*(n-i) - d[n] < T) {
    		int qwe = bs(n,r,T - (d[i]+a*(n-i)-d[n]));
    		res=max(res,qwe-i+1);
    	}

    for(int i=r; i>n; i--) 
    	if(d[i]+a*(i-n)-d[n]<T) {
    		int qwe=bs2(l,n,T - (d[i]+a*(i-n)-d[n]));
    		res=max(res,i-qwe+1);
    	}
    
    cout<<min(res, n)<<"\n";
}