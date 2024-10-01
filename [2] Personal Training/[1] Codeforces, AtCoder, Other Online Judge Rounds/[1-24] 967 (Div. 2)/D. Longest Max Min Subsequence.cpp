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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n;
    cin >> n;
    vector<int> A(n + 1);
    map<int, int> a_mxi;
    set<int> A_distinct;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        a_mxi[A[i]] = i;
        A_distinct.insert(A[i]);
    }

    int nd = A_distinct.size();
    A_distinct.clear();
    vector<int> A_len(n + 1);
    for (int i = n; i >= 1; i--) {
        A_distinct.insert(A[i]);
        A_len[i] = A_distinct.size();
    }
    A_len[0] = A_len[1];

    // for (int x : A_len)
    //     cout << x << ' ';
    // cout << endl;

    int j = 0, prv = 0;
    set<pair<int, int>> available;
    map<int, bool> is_used;
    SegTree *segt = new SegTree(0, n, A_len);
    cout << nd << endl;
    for (int i = nd; i >= 1; i--) {
        while (j + 1 <= n && segt->rangeSumQuery(j + 1, j + 1) >= i) {
            j++;

            if (!is_used[A[j]])
                available.insert({A[j], j});
        }

        // for (auto [x, y] : available)
        //     cout << x << ' ';
        // cout << endl;
        
        assert(!available.empty());

        int a, cur;
        if ((nd - i + 1) % 2 == 0) {
            a = available.begin()->fi;
            cur = INF32;
            while (!available.empty())
                if (available.begin()->fi == a) {
                    cur = min(cur, available.begin()->se);
                    available.erase(available.begin());
                } else
                    break;
        } else {
            a = prev(available.end())->fi;
            cur = INF32;
            while (!available.empty()) 
                if (prev(available.end())->fi == a) {
                    cur = min(cur, prev(available.end())->se);
                    available.erase(prev(available.end()));
                } else
                    break;
        }

        cout << a << ' ';
        // cout << endl;
        
        for (int k = prv + 1; k <= cur; k++)
            if (available.find({A[k], k}) != available.end())
                available.erase({A[k], k});
        prv = cur;
        is_used[a] = true;
        segt->rangeSumUpdate(0, a_mxi[a], -1);
    }
    cout << endl;
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