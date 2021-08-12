#include "bits/stdc++.h"
#define f first
#define s second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef pair<int,int> pii;
const int D = 1e6 + 1;
const int N = 1007;
int n,m;

int cnt[2000015], pos[2*N];
bool valido[2*N];

map<int,int> index;
set<int> caras;

int main() 
{ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin>>n>>m;
	vector<pii> estrela(n);
	vector<pii> eventos;

	for(int i=0;i<n;++i)
		cin>>estrela[i].s>>estrela[i].f;


	for(int i=0;i<m;++i) 	
	{
		int y, x1,x2;
		cin>>y>>x1>>x2;

		//inicio de evento
		eventos.pb(pii(x1,y));

		//fim do evento, y negativo fora do range
		eventos.pb(pii(x2+1,y-2*D));


		//marcar os pontos de inicio/fim dos intervalos
		index[x1] = 0;
		index[x2+1] = 0;
	}


	int cnt_index = 0 ;
	for(auto &[x,id] : index)
	{
  		id = ++cnt_index;
  		pos[cnt_index] = x;
	}

	sort(ALL(eventos));


	// for(int i=0;i<2*m;++i)
	// 	cout<<eventos[i].f<<","<<eventos[i].s<<"\n";

	for(int i=0;i<n;++i) 
	{
		caras.clear();
		memset(valido,false,sizeof(valido));

		for(int j = 0 ; j < 2 * m;)
		{
			int k = j;

			//adiciono todo mundo que tem o mesmo x que eu
			//++ evento ou -- evento
			while(k < 2* m && eventos[k].first == eventos[j].first)
			{
				//-- evento
				if(eventos[k].second < 0)
					caras.erase(eventos[k].second + 2 * D);
				//++ evento 
				else
					caras.insert(eventos[k].second);

				k++;
			}

			//Se tem barras em cima e
			if(caras.lower_bound(estrela[i].s) != caras.begin() && caras.lower_bound(estrela[i].s) != caras.end())         
				valido[index[ eventos[j].first] ] = true;              
			else 
		  		valido[index[ eventos[j].first] ] = false;
		  
			j = k;
		}

		for(int j = 1 ; j < cnt_index; ++ j)
			if(valido[j]) 
			{
				cnt[D + pos[j]	    -	estrela[i].f]++;
				cnt[D + pos[j + 1]	- 	estrela[i].f]--;
			}
		
	}

	//soma de prefixo
	int ans = cnt[0];
	for(int i = 1 ; i <= 2 * D; ++i)
	{
		cnt[i] += cnt[i - 1];
		ans = max(ans, cnt[i]);
	}

  	cout<<ans<<"\n";
  	return 0 ;
 }