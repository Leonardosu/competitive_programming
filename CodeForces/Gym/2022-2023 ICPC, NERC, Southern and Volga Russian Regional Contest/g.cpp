#include "bits/stdc++.h"
using namespace std;

#define endl '\n'

void solvetask(){
    long long k, x; cin >> k >> x;

    long long n = 2 * k - 1;

    auto pa = [](long long x) {
        return x * (x + 1ll) / 2;
    };

    auto get = [&](long long mid) {
        if (mid <= k) {
            return pa(mid);
        }
        return pa(k) + (pa(k - 1) - pa(n - mid));
    };

    long long l = 1, r = n, ans = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (get(mid) < x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << max(1ll, min(n, ans + 1)) << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--) solvetask();
}
