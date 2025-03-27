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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adjl(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }
    string s;
    cin >> s;

    int cnt_0 = 0, cnt_1 = 0, cnt_q = 0, extra_cnt_q = 0;
    for (int i = 1; i < n; i++) {
        if (adjl[i].size() > 1) {
            extra_cnt_q += s[i] == '?';
            continue;
        }

        if (s[i] == '0') {
            cnt_0++;
        } else if (s[i] == '1') {
            cnt_1++;
        } else if (s[i] == '?') {
            cnt_q++;
        }
    }

    if (s[0] == '?') {
        int ans = max(cnt_0, cnt_1) + cnt_q / 2;
        if (cnt_0 == cnt_1 && extra_cnt_q % 2 == 1) 
            ans = max(ans, cnt_0 + (cnt_q + 1) / 2);

        cout << ans << endl;
    } else {
        cout << (s[0] == '0' ? cnt_1 : cnt_0) + (cnt_q + 1) / 2 << endl;
    }

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