// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<lng> as(n), a_sum_largest(n);
    for (int i = 0; i < n; i++) {
        cin >> as[i];
        if (i > 0) {
            as[i] += as[i - 1];
        }

        a_sum_largest[i] = as[i];
        if (i > 0) {
            a_sum_largest[i] = max(a_sum_largest[i], a_sum_largest[i - 1]);
        }
    }

    lng ans = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        ans = max({ans, cur + a_sum_largest[i], cur + as[i]});
        cur += as[i];
    }

    cout << ans << endl;
    
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}