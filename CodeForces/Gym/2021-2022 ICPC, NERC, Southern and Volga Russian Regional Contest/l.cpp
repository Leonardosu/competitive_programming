#include "bits/stdc++.h"
using namespace std;

#define endl '\n'

void solvetask(){
    int n; cin >> n;
    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto best = [](long long trash, long long people) {
        long long l = 0, r = people, ans = 0;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (trash - mid - 2 * (people - mid) > 0) {
                r = mid - 1;
            } else {
                l = mid + 1;
                ans = mid;
            }
        }
        return ans;
    };

    auto can = [&](int mid) {
        vector<long long> b = a;
        for (int i = 0; i < n - 1; i++) {
            if (b[i] > 2 * mid) return false;
            long long to_clean = best(b[i], mid);

            b[i] = max(0ll, b[i] - to_clean);

            b[i + 1] += b[i];
        }
        return b[n - 1] <= mid;
    };

    long long l = 0, r = 2e5 + 1, ans = -1;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) solvetask();
}
