#include "bits/stdc++.h"
using namespace std;

#define endl '\n'

void solvetask(){
    int n[3]; for (int i = 0; i < 3; i++) cin >> n[i];
    vector<string> a[3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n[i]; j++) {
            string x; cin >> x;
            a[i].push_back(x);
        }
    }

    vector<char> v = { 'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U' };

    int cnt[2][3] = { { 0, 0, 0 }, { 0, 0, 0 } };
    for (int r = 0; r < 2; r++) {
        for (int i = 0; i < 3; i++) {
            for (string &x : a[i]) {
                for (char &c : x) {
                    if (find(v.begin(), v.end(), c) != v.end() || (r && (c == 'y' || c == 'Y'))) {
                        cnt[r][i]++;
                    }
                }
            }
        }
    }
    if (cnt[0][0] <= 5 && 5 <= cnt[1][0] &&
        cnt[0][1] <= 7 && 7 <= cnt[1][1] &&
        cnt[0][2] <= 5 && 5 <= cnt[1][2]
       ) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solvetask();
}
