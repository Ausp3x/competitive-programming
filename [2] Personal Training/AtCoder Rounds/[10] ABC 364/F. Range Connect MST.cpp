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
    int N, Q;
    cin >> N >> Q;
    vector<vector<lng>> edjl;
    for (int i = 1; i <= Q; i++) {
        int l, r;
        lng c;
        cin >> l >> r >> c;
        l--; 
        r--;

        edjl.pb({c, i, l, r});
    }

    sort(edjl.begin(), edjl.end());

    set<int> disjoints;
    for (int i = 0; i <= N; i++)
        disjoints.insert(i);

    // for (int x : disjoints)
    //     cout << x << ' ';
    // cout << endl;

    int cnt = 0;
    lng ans = 0;
    for (int i = 0; i < Q; i++) {
        lng c = edjl[i][0], ord = edjl[i][1], l = edjl[i][2], r = edjl[i][3]; 

        auto l_itr = disjoints.lower_bound(l);
        if (l_itr != disjoints.begin() && *l_itr > l)
            l_itr--;
        auto r_itr = disjoints.upper_bound(r);
        
        set<int> cur_disjoints;
        for (auto j = l_itr; j != r_itr; j++) {
            cnt++;
            ans += c;
            if (j != l_itr)
                cur_disjoints.insert(*j);
        } 

        for (int j : cur_disjoints) {
            auto itr = disjoints.find(j);
            disjoints.erase(itr);
        }
        
        // for (int x : disjoints)
        //     cout << x << ' ';
        // cout << endl;
    }

    if (cnt != N + Q - 1) {
        cout << -1 << endl;
        return;
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