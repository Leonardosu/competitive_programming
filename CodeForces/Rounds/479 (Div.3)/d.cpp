#include <bits/stdc++.h>
#define MAXN 110
 
using namespace std;
typedef long long ll;
 
ll seq[MAXN];
set<ll> s;
int n;
 
void display(vector <ll> &v)
{
  for(int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout<<"\n";
}
 
void dfs(ll x, int cont, vector<ll> &v)
{
  if (cont == n - 1)  display(v);
  if (s.find(x*2) != s.end())
  {
    v.push_back(x*2);
    dfs(x*2, ++cont, v);
  }
    
  if (x%3==0 && (s.find(x/3) != s.end()) )
  {  
    v.push_back(x/3);
    dfs(x/3, ++cont, v); 
  } 
  
}
 
int main()
{  
  ios_base::sync_with_stdio(false); cin.tie(0);
 
  cin>>n;
  
  for(int i = 0; i < n; i++)
  {
    cin >> seq[i];
    s.insert(seq[i]);
  }
  
  for(int i = 0; i < n; i++)
  {
    vector<ll> aux;
    aux.push_back(seq[i]);
    dfs(seq[i], 0, aux);
  }
 
}