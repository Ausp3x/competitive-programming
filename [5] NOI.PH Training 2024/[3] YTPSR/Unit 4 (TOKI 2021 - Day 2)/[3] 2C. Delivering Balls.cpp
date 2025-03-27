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
    lng mx = 0, mn = 0;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            mx = mn = arr[l];
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
            pull();
        }
    }

    // pull states up from children
    void pull() {
        if (l_child != nullptr && r_child != nullptr) {
            mx = max(l_child->mx, r_child->mx);
            mn = min(l_child->mn, r_child->mn);
        }

        return;
    }

    lng rangeMaxQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return -INF64;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return mx;
        } 
        
        return max(l_child->rangeMaxQuery(cur_l, cur_r), r_child->rangeMaxQuery(cur_l, cur_r));
    }

    lng rangeMinQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return INF64;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return mn;
        }
        
        return min(l_child->rangeMinQuery(cur_l, cur_r), r_child->rangeMinQuery(cur_l, cur_r));
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has mx " << mx << " and mn " << mn << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> H(n), L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> H[i];
        L[i] = i - H[i];
        R[i] = i + H[i];
    }

    SegTree *Hsegt = new SegTree(0, n - 1, H);
    SegTree *Lsegt = new SegTree(0, n - 1, L);
    SegTree *Rsegt = new SegTree(0, n - 1, R);

    int q;
    cin >> q;
    while (q--) {
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        
        lng m = Hsegt->rangeMaxQuery(min(s, t), max(s, t));
        lng l = Lsegt->rangeMinQuery(min(s, t), max(s, t)) + m;
        lng r = Rsegt->rangeMaxQuery(min(s, t), max(s, t)) - m;

        // cout << m << ' ' << l << ' ' << r << endl;
        cout << 4 * (m - H[s]) + 2 * (r - l) + (m - H[t]) << endl;
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

