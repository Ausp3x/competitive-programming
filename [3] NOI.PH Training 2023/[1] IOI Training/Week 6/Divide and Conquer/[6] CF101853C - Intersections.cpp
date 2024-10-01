// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> line_segments(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        line_segments[a - 1].first = i;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        line_segments[b - 1].second = i;
    }

    sort(line_segments.begin(), line_segments.end());

    lng ans = 0;
    tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> used_line_js;
    for (auto &[i, j] : line_segments) {
        ans += used_line_js.order_of_key(j);

        used_line_js.insert(j);
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