// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    vector<int> W(n);
    for (int &w : W)
        cin >> w;

    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
        m[A[i]].push_back(W[i]);

    lng ans = 0;
    for (auto &[k, v] : m) {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size() - 1; i++)
            ans += v[i];
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