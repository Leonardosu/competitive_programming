#include <bits/stdc++.h>
#define MAXN  1010 
#define C first
#define X second.first
#define Y second.second
#define mp make_pair
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> grafo;

int pai[MAXN],peso[MAXN];
int n,m,a,b,w;

int find(int x)
{
  if(pai[x]==x) return x;
  return pai[x]=find(pai[x]);
}

void join(int x,int y)
{
  x=find(x);
  y=find(y);
  if(x==y) return;
  if(peso[x]<peso[y]) pai[x]=y;
  if(peso[x]>peso[y]) pai[y]=x;
  if(peso[x]==peso[y])
  {
    pai[x]=y;
    peso[y]++;
  }
  return ;
}

int main() // uva 11747
{
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  while(cin>>n>>m && (n+m))
  {
    priority_queue<int, vector<int> ,greater<int> > resp;
    vector<int> fim;
    int pegou=0;
    grafo.clear();
    
    for(int i=0;i<=n;++i)
      {
        pai[i]=i;
        peso[i]=0;
      }
    
    for(int i=0;i<m;++i)
    {
      cin>>a>>b>>w;
      grafo.push_back(mp( w,mp(a,b) ) );
    }
    
    sort(grafo.begin(),grafo.end());
    
    for(int i=0;i<m;++i)
    {
      pair<int,ii> front=grafo[i];

      if(find(front.X)!=find(front.Y))
      {
        join(front.X,front.Y);
        pegou++;
      }
      
      else
        fim.push_back(front.first);
    }


    if(m-pegou==0)
	{
		cout<<"forest\n";
		continue;
	}

    if(fim.size()!=grafo.size())
    {
		for(int i = 0; i<fim.size(); i++)
	    {
	       cout<<fim[i]<<" \n"[i == fim.size() - 1];
	    }
		//continue;
    }
    
    //out<<"teste "<<fim.size()<<' '<<grafo.size()<<'\n';
    
      
  }
  
  return 0;
}