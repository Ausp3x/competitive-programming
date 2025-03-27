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
    lng val = 0, upd = 0;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            val = arr[l];
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
        }
    }

    // push updates down to children
    void push() {
        if (l_child != nullptr && r_child != nullptr) {
            (l_child->upd += upd) %= 26;
            (l_child->val += upd) %= 26;
            (r_child->upd += upd) %= 26;
            (r_child->val += upd) %= 26;
        }
        upd = 0;

        return;
    }

    void rangeSumUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            (upd += x) %= 26;
            return;
        }
        
        push();
        l_child->rangeSumUpdate(cur_l, cur_r, x);
        r_child->rangeSumUpdate(cur_l, cur_r, x);
        return;
    }

    lng singleQuery(int cur) {
        if (r < cur || cur < l) {
            return 0;
        } 
        
        if (cur == l && r == cur) {
            return val;
        } 
        
        push();
        return l_child->singleQuery(cur) + r_child->singleQuery(cur);
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has val " << val << " and upd " << upd << endl;
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
    string s;
    cin >> s;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        A[i] = s[i] - 'a';
    SegTree *segt = new SegTree(0, n - 1, A);

    vector<bool> in_palindrome(n);
    
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