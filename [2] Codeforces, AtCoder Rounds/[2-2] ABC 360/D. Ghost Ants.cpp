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
    int N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    vector<int> X(N);
    for (int &x : X)
        cin >> x;

    vector<vector<lng>> v(2);
    for (int i = 0; i < N; i++) {
        v[S[i] - '0'].push_back(X[i]);
    }

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());

    lng d = 2 * T, ans = 0;
    for (int i = 0; i < v[1].size(); i++) {
        int l = upper_bound(v[0].begin(), v[0].end(), v[1][i] - 1) - v[0].begin();
        int r = upper_bound(v[0].begin(), v[0].end(), v[1][i] + d) - v[0].begin();

        if (l == v[0].size())
            break;

        ans += r - l;
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