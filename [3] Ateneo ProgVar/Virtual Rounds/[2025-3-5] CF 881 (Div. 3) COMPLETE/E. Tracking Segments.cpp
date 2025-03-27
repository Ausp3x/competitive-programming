// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
    int l, r;
    lng sum = 0, upd = 0;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            sum = arr[l];
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
            l_child->upd += upd;
            l_child->getTotalSum();
            r_child->upd += upd;
            r_child->getTotalSum();
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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> segs(m);
    for (auto &[l, r] : segs)
        cin >> l >> r;

    int q;
    cin >> q;
    vector<int> qry(q);
    for (int &x : qry)
        cin >> x;

    int l = 0, r = q + 1;
    while (r - l > 1) {
        int md = (r + l) / 2;

        vector<bool> arr(n + 1);
        for (int i = 0; i < md; i++)
            arr[qry[i]] = true;

        SegTree *segt = new SegTree(1, n, arr);

        bool has_beautiful = false;
        for (auto &[l, r] : segs) {
            int cur = segt->rangeSumQuery(l, r);
            int req = (r - l + 1) / 2 + 1;
            if (cur >= req)
                has_beautiful = true;
        }

        if (has_beautiful)
            r = md;
        else
            l = md;
    }
    
    cout << (r == q + 1 ? -1 : r) << endl;
    // cout << endl;
    
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