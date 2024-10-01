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
    lng l, r;
    cin >> n >> l >> r;
    vector<lng> as(n);
    for (lng &a : as)
        cin >> a;
    
    int j = -1;
    lng sum = 0;
    vector<pair<int, int>> intervals;
    for (int i = 0; i < n; i++) {
        while (sum < l && j < n - 1) {
            sum += as[++j];
        }

        if (l <= sum && sum <= r)
            intervals.push_back({j, i});

        sum -= as[i];
    }

    sort(intervals.begin(), intervals.end());

    int ans = 0, end = -1;
    for (auto &[j, i] : intervals)
        if (i > end) {
            ans++;
            end = j;
        }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}