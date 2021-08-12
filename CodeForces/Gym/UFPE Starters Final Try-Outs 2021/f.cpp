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

inline ll poww(ll a, ll b,ll mod){ll res = 1;while (b > 0){if(b & 1) res = (res * a)%mod;a = (a * a)%mod;b >>= 1;}return res;}

const int maxn = 1e5 + 7;
const int base = 311;
const int mod = 1e9 + 7;
 
vector<string> word;
vector<ll> s1[maxn],s2[maxn];


ll value[maxn], inverso[maxn];
 
void update(int id,int no,int ini,int fim,int x,int v)
{
    if(ini == fim) 
        s1[id][no] = s2[id][no] = v;
    else
    {
        if(x<=mid) update(id,e,ini,mid,x,v);
        else update(id,d,mid+1,fim,x,v);

        s1[id][no] = (s1[id][e]*value[fim-mid] + s1[id][d])%mod;
        s2[id][no] = (s2[id][e] + s2[id][d]*value[mid-ini+1])%mod;
    }
}
 
int query(int id,int no,int ini,int fim,int l,int r,int T)
{
    if(ini == l && r == fim) return T ? s1[id][no] : s2[id][no];
 
    if(r <= mid ) return query(id,e,ini,mid,l,r,T);
    else if(l > mid) return query(id,d,mid+1,fim,l,r,T);
 
    ll a,b;
    if(T == 1)
    {
        a = query(id,e,ini,mid,l,mid,T)*value[r-mid];
        b = query(id,d,mid+1,fim,mid+1,r,T);
    }        
    else
    {
        a = query(id,e,ini,mid,l,mid,T);
        b = value[mid-l+1]*query(id,d,mid+1,fim,mid+1,r,T);
    }
        
    return (a + b)%mod;
}
 
// bool palin(int id,int ini,int fim)
// {
//     if(ini == fim) return true;
 
//     int tam = (fim - ini + 1);
//     int n = word[id].size() - 1;

//     ll a,b;
 
//     if(tam&1)
//         a = query(id,1,1,n,ini,mid-1,1), b = query(id,1,1,n,mid+1,fim,0);
//     else
//         a = query(id,1,1,n,ini,mid,1), b = query(id,1,1,n,mid+1,fim,0);
 
//     if(a == b) return true;
//     else return false;
// }


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	value[0] = 1LL;
    for(int i=1;i<maxn;++i)
    {    	
        value[i] = (value[i-1]*base)%mod;    
    }

	int n,q;
	string s;
	char letra;

	cin>>n>>q;
	for(int i=0;i<n;++i)
	{
		cin>>s;

		s = "$" + s;
		word.pb(s);

		int len = s.size() ;
		s1[i].resize(4*len);
		s2[i].resize(4*len);


		for(int j=1;j<len;++j)
			update(i,1,1,len-1,j,s[j]);
	}

	// cout<<"Ok leitura\n";
	// cout<<query(2,1,1,6,3,4,0)<<"\n";
	// cout<<query(3,1,1,6,4,6,0)<<"\n";

	while(q--)
	{
		int t,i,j;
		int li,ri,lj,rj;

		cin>>t>>i>>j;

		if(t == 1) // word[i][j] = c
		{
			cin>>letra;			
			i--;
			update(i,1,1,word[i].size()-1,j,(int)letra);
			// cout<<"Ok tipo 1\n";
		}
		else
		{			
			cin>>li>>ri>>lj>>rj;

			if(t == 2) // [Li,Ri] == [Lj,Rj]
			{
				ll a = query(i-1,1,1,word[i-1].size()-1,li,ri,0);				
				ll b = query(j-1,1,1,word[j-1].size()-1,lj,rj,0);
				
				if(a < 0)
					a += mod;
				if(b < 0)
					b += mod;

				cout<<((a == b) ? "equal" : "different")<<"\n";
				// cout<<"Ok tipo 2\n";
			}
			else // string1[Li,Ri] + string2[Lj,Rj] == palin
			{
				int a = query(i-1,1,1,word[i-1].size()-1,li,ri,0);
				int b = query(j-1,1,1,word[j-1].size()-1,lj,rj,0);				
				if(a < 0)
					a += mod;
				if(b < 0)
					b += mod;				
				//a + b*base^k
				int prefixo = (a + (b*value[ri-li+1])%mod)%mod;

				
				a =  query(i-1,1,1,word[i-1].size()-1,li,ri,1);
				b =  query(j-1,1,1,word[j-1].size()-1,lj,rj,1);
				if(a < 0)
					a += mod;
				if(b < 0)
					b += mod;
				//sufixo a*base^k + b				
				int sufixo = ((a*value[rj-lj+1])%mod + b)%mod;
				
				cout<<((prefixo != sufixo) ? "not so " : "")<<"cool\n";
			}
		}

	}
}
/*

output
equal
equal
not so cool
cool
cool
different
*/
