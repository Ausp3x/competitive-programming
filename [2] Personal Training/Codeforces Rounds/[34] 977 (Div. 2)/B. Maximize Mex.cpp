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

void solve() {
    int n;
    lng x;
    cin >> n >> x;
    map<lng, int> cnts;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        cnts[a]++;
    }

    // for (auto &[k, v] : cnts) 
    //     cout << '[' << k << ", " << v << "] ";
    // cout << endl;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (cnts.empty())
            break;

        while (cnts.begin()->fi < ans) {
            auto [cur, cnt] = *cnts.begin();
            cnts.erase(cnts.begin());

            if (cnt != 0)
                cnts[cur + x] += cnt;
        }

        if (cnts.begin()->fi > ans)
            break;

        // for (auto &[k, v] : cnts) 
        //     cout << '[' << k << ", " << v << "] ";
        // cout << endl;

        ans = i;
        cnts[i - 1]--;
        if (cnts[i - 1] != 0)
            cnts[i + x - 1] += cnts[i - 1];
        cnts.erase(i - 1);
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