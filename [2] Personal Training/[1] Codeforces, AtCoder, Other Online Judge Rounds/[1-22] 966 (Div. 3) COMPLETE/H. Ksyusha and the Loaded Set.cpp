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
    lng mn = 0;
    SegTree *l_child, *r_child;

    SegTree(int l, int r, const vector<int> &arr): l(l), r(r) {
        if (l == r) {
            mn = arr[l];
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
            mn = min(l_child->mn, r_child->mn);
        }

        return;
    }

    void singleMinUpdate(int cur, lng x) {
        if (r < cur || cur < l) {
            return;
        }
        
        if (cur == l && r == cur) {
            mn = x;
            return;
        }
        
        l_child->singleMinUpdate(cur, x);
        r_child->singleMinUpdate(cur, x);
        pull();
        return;
    }

    lng rangeMinQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return INF32;
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
        cout << "[" << l << ", " << r << "] has min val " << mn << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

int N = 2000000;
vector<set<int>> LI(N + 1, {N + 1});
SegTree *segt = new SegTree(0, N, vector<int>(N + 1, N + 1));

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 2);
    ordered_set<int> Ao;
    A[0] = 0;
    A[n + 1] = INF32;
    Ao.insert(0);
    Ao.insert(INF32);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        Ao.insert(A[i]);
    }
    
    set<int> not_reset;
    for (int i = 0; i <= n; i++) {
        LI[min(A[i + 1] - A[i] - 1, N)].insert(A[i] + 1);
        if (LI[min(A[i + 1] - A[i] - 1, N)].size() > 1)
            not_reset.insert(min(A[i + 1] - A[i] - 1, N));
    }

    for (int i : not_reset)
        segt->singleMinUpdate(i, *LI[i].begin());

    int m;
    cin >> m;
    while (m--) {
        char c;
        cin >> c;

        if (c == '+') {
            int x;
            cin >> x;

            Ao.insert(x);

            int m = Ao.order_of_key(x);
            int l = m - 1, r = m + 1;
            int x_l = *Ao.find_by_order(l), x_r = *Ao.find_by_order(r);

            int D = min(x_r - x_l - 1, N), d1 = min(x - x_l - 1, N), d2 = min(x_r - x - 1, N);

            if (x_l + 1 != N + 1)
                LI[D].erase(x_l + 1);
            segt->singleMinUpdate(D, *LI[D].begin());
            if (LI[D].size() == 1)
                not_reset.erase(D);

            LI[d1].insert(x_l + 1);
            segt->singleMinUpdate(d1, *LI[d1].begin());
            if (LI[d1].size() > 1)
                not_reset.insert(d1);
            
            LI[d2].insert(x + 1);
            segt->singleMinUpdate(d2, *LI[d2].begin());
            if (LI[d2].size() > 1)
                not_reset.insert(d2);
        } else if (c == '-') {
            int x;
            cin >> x;

            int m = Ao.order_of_key(x);
            int l = m - 1, r = m + 1;
            int x_l = *Ao.find_by_order(l), x_r = *Ao.find_by_order(r);

            int D = min(x_r - x_l - 1, N), d1 = min(x - x_l - 1, N), d2 = min(x_r - x - 1, N);

            if (x_l + 1 != N + 1)
                LI[d1].erase(x_l + 1);
            segt->singleMinUpdate(d1, *LI[d1].begin());
            if (LI[d1].size() == 1)
                not_reset.erase(d1);

            if (x + 1 != N + 1)
                LI[d2].erase(x + 1);
            segt->singleMinUpdate(d2, *LI[d2].begin());
            if (LI[d2].size() == 1)
                not_reset.insert(d2);
            
            LI[D].insert(x_l + 1);
            segt->singleMinUpdate(D, *LI[D].begin());
            if (LI[D].size() > 1)
                not_reset.insert(D);

            Ao.erase(x);
        } else if (c == '?') {
            int k;
            cin >> k;

            cout << segt->rangeMinQuery(k, N) << ' '; 
        }
    }
    cout << endl;

    for (int i : not_reset) {
        while (LI[i].size() > 1)
            LI[i].erase(LI[i].begin());
        
        segt->singleMinUpdate(i, N + 1);
    }

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