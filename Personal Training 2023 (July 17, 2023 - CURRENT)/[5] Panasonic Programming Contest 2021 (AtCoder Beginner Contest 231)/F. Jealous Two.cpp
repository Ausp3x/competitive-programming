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
    vector<pair<int, int>> a_bs(n);
    for (auto &[a, b] : a_bs) {
        cin >> a;
    }
    for (auto &[a, b] : a_bs) {
        cin >> b;
    }

    sort(a_bs.begin(), a_bs.end());

    int j = -1;
    lng ans = 0;
    tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> before;
    for (int i = 0; i < n; i++) {
        if (i > j) {
            j = i;
            before.insert({a_bs[j].second, j});

            while (j < n - 1) {
                if (a_bs[j].first == a_bs[j + 1].first) {
                    j++;
                    before.insert({a_bs[j].second, j});
                } else {
                    break;
                }
            }
        }

        ans += before.size() - before.order_of_key({a_bs[i].second, 0});   
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