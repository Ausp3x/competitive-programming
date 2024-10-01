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

struct SegTree {    
    int l, r;
    lng min_val = INF64, min_cnt = 0, upd = 0;
    SegTree *l_child, *r_child;

    SegTree(int l, int r, const vector<int> &arr): l(l), r(r) {
        if (l == r) {
            min_val = arr[l];
            min_cnt = 1;
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
            pull();
        }
    }

    // push updates down to children
    void push() {
        if (l_child != nullptr && r_child != nullptr) {
            l_child->min_val += upd;
            l_child->upd += upd;
            r_child->min_val += upd;
            r_child->upd += upd;
        }
        upd = 0;

        return;
    }

    // pull states up from children
    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            if (l_child->min_val < r_child->min_val) {
                min_val = l_child->min_val;
                min_cnt = l_child->min_cnt;
            } else if (r_child->min_val < l_child->min_val) {
                min_val = r_child->min_val;
                min_cnt = r_child->min_cnt;
            } else {
                min_val = l_child->min_val;
                min_cnt = l_child->min_cnt + r_child->min_cnt;     
            }
        }

        return;
    }

    void rangeSumUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }
        
        if (cur_l <= l && r <= cur_r) {
            min_val += x;
            upd += x;
            push();
            return;
        }
        
        push();
        l_child->rangeSumUpdate(cur_l, cur_r, x);
        r_child->rangeSumUpdate(cur_l, cur_r, x);
        pull();
        return;
    }

    // TODO: implement function
    pair<lng, lng> rangeMinCntQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return {INF64, 0};
        }

        if (cur_l <= l && r <= cur_r) {
            return {min_val, min_cnt};
        }

        push();
        pair<lng, lng> l_query = l_child->rangeMinCntQuery(cur_l, cur_r);
        pair<lng, lng> r_query = r_child->rangeMinCntQuery(cur_l, cur_r);

        if (l_query.fi < r_query.fi) {
            return l_query;
        } else if (r_query.fi < l_query.fi) {
            return r_query;
        } else {
            return {l_query.fi, l_query.se + r_query.se}; 
        }
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has min_val " << min_val << ", min_cnt " << min_cnt << ", and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> AB(m);
    for (auto &[a, b] : AB) {
        cin >> a >> b;
        a--;
        b--;
    }

    vector<vector<int>> bgns(n), ends(n);
    SegTree *segt = new SegTree(0, n - 1, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        bgns[AB[i].fi].pb(i);
        ends[AB[i].se].pb(i);
        segt->rangeSumUpdate(AB[i].fi, AB[i].se - 1, 1);
    }

    lng ans = n - segt->rangeMinCntQuery(0, n - 1).se;
    for (int i = 0; i < n; i++) {
        for (int j : bgns[i]) {
            segt->rangeSumUpdate(AB[j].fi, AB[j].se - 1, -1);
            segt->rangeSumUpdate(AB[j].se, n - 1, 1);
            segt->rangeSumUpdate(0, AB[j].fi - 1, 1);
        }

        for (int j : ends[i]) {
            segt->rangeSumUpdate(AB[j].se, n - 1, -1);
            segt->rangeSumUpdate(0, AB[j].fi - 1, -1);
            segt->rangeSumUpdate(AB[j].fi, AB[j].se - 1, 1);
        }
        
        ans = min(ans, n - segt->rangeMinCntQuery(0, n - 1).se);
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