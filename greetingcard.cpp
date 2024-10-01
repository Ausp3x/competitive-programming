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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

/*
print('{', end = '')
for i in range(-2018, 2019):
    for j in range(-2018, 2019):
        if i * i + j * j == 2018 * 2018:
            print(f'{{{i}, {j}}}, ', end = '')
print('}')
*/

vector<pair<int, int>> dx_dy = {{-2018, 0}, {-1680, -1118}, {-1680, 1118}, {-1118, -1680}, {-1118, 1680}, {0, -2018}, {0, 2018}, {1118, -1680}, {1118, 1680}, {1680, -1118}, {1680, 1118}, {2018, 0}};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    map<pair<int, int>, bool> chk;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        points.pb({x, y});
        chk[{x, y}] = true;
    }

    int ans = 0;
    for (auto &[x, y] : points) {
        for (auto [dx, dy] : dx_dy)
            ans += chk[{x + dx, y + dy}];
    }

    cout << ans / 2 << endl;

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