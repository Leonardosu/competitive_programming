#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
#define mid ( (ini+fim) >> 1LL)
#define e (no<<1)
#define d (no<<1) + 1
using namespace std;
typedef long long int ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

const int maxn = 1e5 + 7;
const ll base = 311;
const ll mod = 1e9 + 7;


ll s1[4*maxn], s2[4*maxn], value[maxn], inverso[maxn];
string s;
int n,q;

void update(int no,int ini,int fim,int x,int v)
{
    if(ini == fim) 
        s1[no] = s2[no] = v;
    else
    {
        if(x<=mid) update(e,ini,mid,x,v);
        else update(d,mid+1,fim,x,v);
        s1[no] = (s1[e]*value[fim-mid] + s1[d])%mod;
        s2[no] = (s2[e] + s2[d]*value[mid-ini+1])%mod;
    }
}

int query(int no,int ini,int fim,int l,int r,int T)
{
    if(ini == l && r == fim) return T ? s1[no] : s2[no];

    if(r <= mid ) return query(e,ini,mid,l,r,T);
    else if(l > mid) return query(d,mid+1,fim,l,r,T);

    ll a,b;
    if(T == 1)
    {
        a = query(e,ini,mid,l,mid,T)*value[r-mid];
        b = query(d,mid+1,fim,mid+1,r,T);
    }        
    else
    {
        a = query(e,ini,mid,l,mid,T);
        b = value[mid-l+1]*query(d,mid+1,fim,mid+1,r,T);
    } 
        
    return (a + b)%mod;
}

bool palin(int ini,int fim)
{
    if(ini == fim) return true;

    int tam = (fim - ini + 1);
    ll a,b,c;

    if(tam&1)
        a = query(1,1,n,ini,mid-1,1), b = query(1,1,n,mid+1,fim,0);
    else
        a = query(1,1,n,ini,mid,1), b = query(1,1,n,mid+1,fim,0);

    if(a == b) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    value[0] = 1LL;
    for(int i=1;i<maxn;++i)
        value[i] = (value[i-1]*base)%mod;    

    int t;
    cin>>t;
    while(t--)
    {

        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        cin>>n>>q;
        cin>>s;
        s = " " + s;
                
        for(int i=1;i<=n;++i)
            update(1,1,n,i,s[i]);        

        while(q--)
        {
            char c;
            int op,pos,l,r;
            cin>>op;

            if(op == 1)
            {
                cin>>pos>>c;
                update(1,1,n,pos,c);
                s[pos] = c;
            }
            else
            {
                cin>>l>>r;
                if(palin(l,r))
                    cout<<"Adnan Wins\n";
                else
                    cout<<"ARCNCD!\n";
            }
        }
    }       


}