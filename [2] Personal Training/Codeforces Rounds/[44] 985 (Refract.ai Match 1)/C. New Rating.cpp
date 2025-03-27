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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct SegTree {
    int l, r, dep;
    int mn, mx, upd = 0;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, int dep, const vector<T> &arr): l(l), r(r), dep(dep) {
        if (l == r) {
            mn = mx = l;
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, dep + 1, arr);
            l_child->dep = dep + 1;
            r_child = new SegTree(m + 1, r, dep + 1, arr);
            r_child->dep = dep + 1;
            pull();
        }
    }

    // push updates down to children
    void push() {
        if (l_child != nullptr && r_child != nullptr) {
            l_child->mn += upd;
            l_child->mx += upd;
            l_child->upd += upd;
            r_child->mn += upd;
            r_child->mx += upd;
            r_child->upd += upd;
        }
        upd = 0;

        return;
    }

    // pull states up from children
    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            mn = min(l_child->mn, r_child->mx);
            mx = max(l_child->mn, r_child->mx);
        }

        return;
    }

    void rangeUpdate(int m) {
        assert(dep == 0);

        auto [l_cur, r_cur] = rangeEdit(m);
        assert(l_cur != -1 && r_cur != -1);
        rangeAdd(l, l_cur - 1, -1);
        rangeAdd(r_cur + 1, r, 1);

        return;
    }

    pair<int, int> rangeEdit(int m) {
        if (mx < m || m < mn) {
            return {-1, -1};
        }

        if (mn <= m && m <= mx && l == r) {
            mn--;
            mx++;
            return {l, r};
        }

        push();
        auto [a, b] = l_child->rangeEdit(m);
        auto [c, d] = r_child->rangeEdit(m);
        pull();

        return {max(a, c), max(b, d)};
    }

    void rangeAdd(int cur_l, int cur_r, int x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            mn += x;
            mx += x;
            upd += x;
            return;
        }
        
        push();
        l_child->rangeAdd(cur_l, cur_r, x);
        r_child->rangeAdd(cur_l, cur_r, x);
        pull();
        
        return;
    }

    int singleQuery(int m) {
        if (mx < m || m < mn) {
            return -1;
        }
        
        if (mn <= m && m <= mx && l == r) {
            return l;
        }

        push();
        return max(l_child->singleQuery(m), r_child->singleQuery(m));
    }

    void debugPrint() {
        for (int t = 0; t < dep; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has mn " << mn << ", mx " << mx << ", and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint();
            r_child->debugPrint();
        }

        return;
    }

    void debugPrintClean() {
        for (int t = 0; t < dep; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has mn " << mn << ", mx " << mx << ", and upd " << upd << endl;
        push();
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint();
            r_child->debugPrint();
        }
        pull();

        return;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    if (n == 2) {
        cout << 1 << endl;
        return;
    }

    vector<int> B(n);
    for (int i = 1; i <= n - 1; i++) {
        B[i] = B[i - 1];
        if (A[i] != B[i - 1])
            B[i] += (A[i] - B[i - 1]) / abs(A[i] - B[i - 1]);
    }

    vector<int> B_max(n);
    for (int i = 1; i <= n - 1; i++)
        B_max[i] = max(B_max[i - 1], B[i]);

    SegTree *segt = new SegTree(0, n + 1, 0, vector<int>(n + 2));

    int ans = B_max[n - 1];
    for (int i = n; i >= 2; i--) {
        segt->rangeUpdate(A[i]);

        // cout << B_max[i - 2] << ' ' << segt->singleQuery(B_max[i - 2]) << endl;

        ans = max<lng>(ans, segt->singleQuery(B_max[i - 2]));

        // segt->debugPrint();
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