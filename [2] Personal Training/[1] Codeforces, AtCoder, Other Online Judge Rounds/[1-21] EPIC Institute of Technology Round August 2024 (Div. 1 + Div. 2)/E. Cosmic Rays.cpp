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
typedef long long lng;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    
    lng a_max = 0;
    // lifetime, color
    stack<pair<lng, int>> S;
    while (n--) {
        lng a;
        int b;
        cin >> a >> b;

        lng da = 0;
        while (!S.empty()) {
            if (b == S.top().se) {
                a += max(S.top().fi - da, 0ll);
                S.pop();
            } else if (a > S.top().fi) {
                da = max(da, S.top().fi);
                S.pop();
            } else {
                break;
            }
        }

        a_max = max(a_max, a);
        S.push({a, b});

        cout << a_max << ' ';
    }
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