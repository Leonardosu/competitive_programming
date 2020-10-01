#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define all(x) x.begin(),x.end()
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef pair<long double,long double> ii;
typedef pair<int,int> pii;
typedef vector<int> vi;

inline ll poww(ll a, ll b, ll mod){ll res = 1;while (b > 0){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}
const int mod = 1e9 + 7;
const long double eps = 1e-8;

long double dist(ii a,ii b)
{
    long double xx = a.x - b.x, yy = a.y - b.y;
    return sqrt(xx*xx + yy*yy);
}

ii novoponto(ii a,ii b,long double t)
{
    return {a.x + (b.x-a.x)*t, a.y + (b.y-a.y)*t};
}

long double solve(ii a,ii b,ii c,ii d) // tamanhos iguais
{
    long double l = 0.0,r = 1.0;    

    if(dist(a,b) - dist(c,d) > eps)
        swap(a,c),swap(b,d);

    if (c == d)
        return (dist(c,b));

    long double limit = dist(a,b)/dist(c,d);
    long double resp1,resp2;

    for(int i=0;i<100000;++i)
    {
        long double t1 = l + (r - l) / 3.0;
        long double t2 = r - (r - l) / 3.0;

        ii p1 = novoponto(a,b,t1);
        ii p2 = novoponto(c,d,t1*limit);
        long double ans1 = dist(p1,p2);

        p1 = novoponto(a,b,t2);
        p2 = novoponto(c,d,t2*limit);
        long double ans2 = dist(p1,p2);

        if (ans1 - ans2 > eps)
            l = t1;                           
        else        
            r = t2;                     
    }

    resp1 = dist(novoponto(a,b,l),novoponto(c,d,l*limit));
    l = 0.0, r = 1.0;
    
    for(int i=0;i<100000;++i)
    {
        long double t1 = l + (r - l) / 3.0;
        long double t2 = r - (r - l) / 3.0;

        ii p1 = novoponto(b,b,1.0);
        ii p2 = novoponto(c,d,limit + (1.0-limit)*t1);
        long double ans1 = dist(p1,p2);

        p1 = novoponto(b,b,1.0);
        p2 = novoponto(c,d,limit + (1.0-limit)*t2);
        long double ans2 = dist(p1,p2);

        if (ans1 - ans2 > eps)
            l = t1;                           
        else        
            r = t2;                     
    }

    resp2 = dist(novoponto(a,b,1.0),novoponto(c,d,l*(1.0-limit) + limit));

    if(resp1 - resp2 > eps) return resp2;
    return resp1;    
}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    ii a,b,c,d;
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;    
    cout<<fixed<<setprecision(15);
    cout<<solve(a,b,c,d)<<"\n";    
}