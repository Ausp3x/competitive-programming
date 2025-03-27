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
    int n, x, y;
    cin >> n >> x >> y;
    x--;
    y--;

    vector<int> ans(n, -1);
    for (int i = y; i <= x; i++)
        ans[i] = 1;
    for (int i = y - 2; i >= 0; i -= 2)
        ans[i] = 1;
    for (int i = x + 2; i < n; i += 2) 
        ans[i] = 1;

    for (int x : ans)
        cout << x << ' ';
    cout << endl;

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