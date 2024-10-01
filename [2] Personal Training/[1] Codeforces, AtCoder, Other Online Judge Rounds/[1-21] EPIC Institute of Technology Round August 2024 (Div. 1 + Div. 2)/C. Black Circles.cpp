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
    int n;
    cin >> n;
    vector<pair<lng, lng>> XY(n);
    for (auto &[x, y] : XY)
        cin >> x >> y;

    lng xs, ys, xt, yt;
    cin >> xs >> ys >> xt >> yt;
    
    lng d = abs(xt - xs) * abs(xt - xs) + abs(yt - ys) * abs(yt - ys);
    for (auto [x, y] : XY) {
        lng cur_d = abs(xt - x) * abs(xt - x) + abs(yt - y) * abs(yt - y);
        if (cur_d <= d) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    
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