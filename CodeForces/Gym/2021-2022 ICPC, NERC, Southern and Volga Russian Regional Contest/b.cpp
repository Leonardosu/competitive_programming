#include "bits/stdc++.h"
using namespace std;

#define endl '\n'

void solvetask(){
    int n, a, b; cin >> n >> a >> b;

    vector<int> c(n + 1), used(n + 1);
    used[a] = used[b] = 1;
    c[1] = a;
    c[n / 2 + 1] = b;
    for (int i = 2, p = n; i <= n / 2; i++) {
        while (used[p]) p--;
        used[p] = true;
        c[i] = p;
    }
    for (int i = n / 2 + 2, p = 1; i <= n; i++) {
        while (used[p]) p++;
        used[p] = true;
        c[i] = p;
    }
    int mn = n + 1, mx = 0;
    for (int i = 1; i <= n / 2; i++) mn = min(mn, c[i]);
    for (int i = (n / 2) + 1; i <= n; i++) mx = max(mx, c[i]);

    if (mn != a || mx != b) cout << -1 << endl;
    else {
        for (int i = 1; i <= n; i++) cout << c[i] << " ";
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solvetask();
}
