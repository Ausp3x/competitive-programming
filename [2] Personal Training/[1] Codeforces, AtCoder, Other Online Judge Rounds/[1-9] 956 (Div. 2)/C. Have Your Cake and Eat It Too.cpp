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

void solve(int t) {
    int n;
    cin >> n;
    lng tot = 0;
    vector<vector<int>> V(3, vector<int>(n));
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++) {
            cin >> V[i][j];
            if (i == 0)
                tot += V[i][j];
        }
    
    tot = (tot + 2) / 3;

    vector<int> order = {0, 1, 2};
    do {
        bool is_valid = true;
        vector<pair<int, int>> ans(3, {-1, -1});
        for (int i = 0; i < 3; i++) {
            int l = max({ans[0].se, ans[1].se, ans[2].se}) + 1, r = l - 1;
            lng cur_tot = 0;
            while (r + 1 < n && cur_tot < tot)
                cur_tot += V[order[i]][++r];

            if (cur_tot < tot) {
                is_valid = false;
                break;
            }

            ans[order[i]] = {l, min(r, n - 1)};
        }

        if (!is_valid)
            continue;

        for (int i = 0; i < 3; i++) {
            cout << ans[i].fi + 1 << ' ' << ans[i].se + 1 << ' ';
        }
        cout << endl;
        return;
    } while (next_permutation(order.begin(), order.end()));

    cout << -1 << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}