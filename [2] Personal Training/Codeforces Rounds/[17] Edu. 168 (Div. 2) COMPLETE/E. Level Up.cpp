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
    lng sum = 0, upd = 0;
    SegTree *l_child, *r_child;

    SegTree(int l, int r, const vector<int> &arr): l(l), r(r) {
        if (l == r) {
            sum += arr[l];
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
        sum = getTotalSum();
        if (l_child != nullptr && r_child != nullptr) {
            l_child->upd += upd;
            r_child->upd += upd;
        }
        upd = 0;

        return;
    }

    // pull states up from children
    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            sum = l_child->getTotalSum() + r_child->getTotalSum();
        }

        return;
    }

    void rangeSumUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            upd += x;
            return;
        }
        
        push();
        l_child->rangeSumUpdate(cur_l, cur_r, x);
        r_child->rangeSumUpdate(cur_l, cur_r, x);
        pull();
        return;
    }

    lng rangeSumQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return getTotalSum();
        } 
        
        push();
        return l_child->rangeSumQuery(cur_l, cur_r) + r_child->rangeSumQuery(cur_l, cur_r);
    }

    lng getTotalSum() {
        return sum + (r - l + 1) * upd;
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has sum " << sum << " and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    // for (int k = 1; k <= n; k++) {
    //     cout << k << ": ";

    //     int fought = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (fought / k <= A[i]) {
    //             fought++;
    //             cout << 1 << ' ';
    //         } else {
    //             cout << 0 << ' ';
    //         }
    //     }
    //     cout << endl;
    // }

    vector<int> ans(n, -1);
    SegTree *segt = new SegTree(0, 200000, vector<int>(200001, 0));
    for (int i = 0; i < n; i++) {
        int l = 0, r = 200001;
        while (r - l > 1) {
            int md = (l + r) / 2;

            if (segt->rangeSumQuery(md, md) / md + 1 > A[i])
                l = md;
            else
                r = md;
        }

        ans[i] = r;
        segt->rangeSumUpdate(r, 200000, 1);
    }

    // for (int x : ans)
    //     cout << x << ' ';
    // cout << endl;

    while (q--) {
        int i, x;
        cin >> i >> x;
        i--;

        if (i < x - 1) {
            cout << "YES" << endl;
            continue;
        }

        cout << (x >= ans[i] ? "YES" : "NO") << endl;
    }
    
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