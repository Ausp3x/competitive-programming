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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct MergeSortTree {    
    int l, r;
    indexed_set<lng> sorted;
    MergeSortTree *l_child, *r_child;

    // all values must be distinct
    template<class T> 
    MergeSortTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            sorted.insert(arr[l]);
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new MergeSortTree(l, m, arr);
            r_child = new MergeSortTree(m + 1, r, arr);
            pull();
        }
    }

    // pull states up from children
    void pull() {
        if (l_child != nullptr && r_child != nullptr) {
            for (lng x : l_child->sorted)
                sorted.insert(x);
            for (lng x : r_child->sorted)
                sorted.insert(x);
        }

        return;
    }

    // 0-indexed
    int getPosInSortedSubarray(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        }

        if (cur_l <= l && r <= cur_r) {
            return sorted.order_of_key(x);
        } 

        return l_child->getPosInSortedSubarray(cur_l, cur_r, x) + r_child->getPosInSortedSubarray(cur_l, cur_r, x);
    }

    lng rangeMedianQuery(int cur_l, int cur_r, lng l = 0, lng r = 1e18) {
        int req = (cur_r - cur_l + 1) / 2;
        while (r - l > 1) {
            lng md = (l + r) / 2;

            int pos = getPosInSortedSubarray(cur_l, cur_r, md);
            if (pos <= req)
                l = md;
            else 
                r = md;
        }
        
        return l;
    }

    
};

void solve() {
    MergeSortTree *segt = new MergeSortTree(0, 5, vector<int>({3, 2, 4, 1, 6, 5}));
    
    cout << segt->rangeMedianQuery(0, 5) << endl;

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