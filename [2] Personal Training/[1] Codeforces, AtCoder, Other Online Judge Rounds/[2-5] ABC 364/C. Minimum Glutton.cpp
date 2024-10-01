// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int N;
    lng X, Y;
    cin >> N >> X >> Y;
    vector<pair<int, int>> AB(N);
    for (auto &[a, b] : AB)
        cin >> a;
    for (auto &[a, b] : AB)
        cin >> b;

    sort(AB.begin(), AB.end(), greater<pair<int, int>>());

    int ans1 = 0;
    lng X_cur = 0, Y_cur = 0;
    for (int i = 0; i < N; i++) {
        X_cur += AB[i].fi;
        Y_cur += AB[i].se;

        ans1++;
        if (X_cur > X || Y_cur > Y)
            break;
    }

    for (auto &[a, b] : AB)
        swap(a, b);
    sort(AB.begin(), AB.end(), greater<pair<int, int>>());

    int ans2 = 0;
    X_cur = 0, Y_cur = 0;
    for (int i = 0; i < N; i++) {
        X_cur += AB[i].se;
        Y_cur += AB[i].fi;

        ans2++;
        if (X_cur > X || Y_cur > Y)
            break;
    }

    cout << min(ans1, ans2) << endl;

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