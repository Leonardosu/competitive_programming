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

    string s;
    cin>>s;
    stack<int> blocos;
    int qnt = 0;
    for(char &c : s) {
        int x = c - '0';

        if(!blocos.empty()) {
            if(blocos.top() + x == 1) {
                blocos.pop();
                qnt++;
            } else {
                blocos.push(x);
            }
        } else {
            blocos.push(x);
        }
    }

    cout<<2*qnt<<"\n";
}