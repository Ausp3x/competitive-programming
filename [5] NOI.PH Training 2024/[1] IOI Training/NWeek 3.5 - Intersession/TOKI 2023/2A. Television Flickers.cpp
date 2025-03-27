// 人外有人，天外有天
// author: Ausp3x

// #pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
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
    int n, p;
    cin >> n >> p;
    bool subtask_2_chk = true;
    vector<pair<int, int>> actions;
    vector<int> ls, rs;
    for (int i = 0; i < p; i++) {
        int t, w;
        cin >> t >> w;
        
        if (t == 1) {
            actions.pb({1, w});
            ls.pb(1);
            rs.pb(w);
        } if (t == 2) {
            actions.pb({w, n});
            ls.pb(w);
            rs.pb(n);
        }

        subtask_2_chk &= (t == 1 && w == n) || (t == 2 && w == 1);
    }

    // for (auto [l, r] : actions)
    //     cout << l << ' ' << r << endl;
    // cout << endl;

    if (subtask_2_chk) {
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;
            
            cout << actions.size() % 2 << endl;
        }

        return;
    }

    if (n <= 2000) {
        int q;
        cin >> q;
        while (q--) {
            int x, y;
            cin >> x >> y;

            bool state = 0;
            for (int i = 0; i < p; i++) {
                auto [l, r] = actions[i];
                if (l <= x && x <= r && l <= y && y <= r)
                    state ^= 1;
            }

            cout << state << endl;
        }

        return;
    }

    sort(ls.begin(), ls.end());
    sort(rs.begin(), rs.end());

    // for (int x : ls)
    //     cout << x << ' ';
    // cout << endl;
    // for (int x : rs)
    //     cout << x << ' ';
    // cout << endl;

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);

        int l1 = 0, r1 = p - 1;
        while (l1 <= r1) {
            int md = (l1 + r1) / 2;

            if (ls[md] <= x)
                l1 = md + 1;
            else
                r1 = md - 1;
        } 

        int l2 = 0, r2 = p - 1;
        while (l2 <= r2) {
            int md = (l2 + r2) / 2;

            if (rs[md] < y) 
                l2 = md + 1;
            else
                r2 = md - 1;
        }

        // cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << endl;

        if (l2 > r1)
            cout << 0 << endl;
        else
            cout << (r1 - l2 + 1) % 2 << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}