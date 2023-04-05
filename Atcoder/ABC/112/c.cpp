#include "bits/stdc++.h"
#define f first
#define s second
#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) x.begin(),x.end()
#define present(c, x) (c.find(x) != c.end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin>>n;
    vector<array<int,3>> v(n);

    array<int,3> pivot = {0,0,0};

    for (auto &[x, y, h] : v) {
    	cin>>x>>y>>h;
        if (h != 0) {
        	pivot = {x,y,h};
        }
    }

    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++) {
            bool flag = true;
            int H = abs(i - pivot[0]) + abs(j - pivot[1]) + pivot[2];
            for(auto [x, y, h] : v) {
            	if (max(H - abs(x - i) - abs(y - j), 0) != h) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << i << ' ' << j << ' ' << H << endl;
                return 0;
            }
        }

}