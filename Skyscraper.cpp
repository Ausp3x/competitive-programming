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
    lng mn = INF64, mx = -INF64, sum = 0;
    lng add_upd = 0, set_upd = 0;
    bool set_flag = false;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            assert(-INF64 < arr[l] && arr[l] < INF64);
            mn = mx = sum = arr[l];
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
            if (set_flag) {
                l_child->add_upd = 0;
                l_child->set_upd = set_upd;
                l_child->set_flag = true;
                l_child->mn = l_child->mx = set_upd;
                l_child->sum = l_child->getRange() * set_upd;
                
                r_child->add_upd = 0;
                r_child->set_upd = set_upd;
                r_child->set_flag = true;
                r_child->mn = r_child->mx = set_upd;
                r_child->sum = r_child->getRange() * set_upd;
                
                set_upd = 0;
                set_flag = false;
            }

            if (add_upd != 0) {
                l_child->add_upd += add_upd;
                l_child->mn += add_upd;
                l_child->mx += add_upd;
                l_child->sum += l_child->getRange() * add_upd;
                
                r_child->add_upd += add_upd;
                r_child->mn += add_upd;
                r_child->mx += add_upd;
                r_child->sum += r_child->getRange() * add_upd;

                add_upd = 0;
            }
        }

        return;
    }

    // pull states up from children
    void pull() {
        assert(add_upd == 0 && set_upd == 0 && !set_flag);
        if (l_child != nullptr && r_child != nullptr) {
            mn = min(l_child->mn, r_child->mn);
            mx = max(l_child->mx, r_child->mx);
            sum = l_child->sum + r_child->sum;
        }

        return;
    }

    void rangeAddUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }
        
        if (cur_l <= l && r <= cur_r) {
            if (set_flag) 
                set_upd += x;
            else 
                add_upd += x; 
            mn += x;
            mx += x;
            sum += (r - l + 1) * x;
            return;
        }
        
        push();
        l_child->rangeAddUpdate(cur_l, cur_r, x);
        r_child->rangeAddUpdate(cur_l, cur_r, x);
        pull();

        return;
    }

    void rangeSetUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }
        
        if (cur_l <= l && r <= cur_r) {
            set_upd = x;
            set_flag = true;
            mn = mx = set_upd;
            sum = (r - l + 1) * set_upd;
            return;
        }
        
        push();
        l_child->rangeSetUpdate(cur_l, cur_r, x);
        r_child->rangeSetUpdate(cur_l, cur_r, x);
        pull();

        return;
    }

    lng rangeMaxQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return -INF64;
        }

        if (cur_l <= l && r <= cur_r) {
            return mx;
        }
        
        push();

        return max(l_child->rangeMaxQuery(cur_l, cur_r), r_child->rangeMaxQuery(cur_l, cur_r));
    }

    lng rangeMinQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return INF64;
        }

        if (cur_l <= l && r <= cur_r) {
            return mn;
        }
        
        push();

        return min(l_child->rangeMinQuery(cur_l, cur_r), r_child->rangeMinQuery(cur_l, cur_r));
    }

    lng rangeSumQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return sum;
        } 
        
        push();

        return l_child->rangeSumQuery(cur_l, cur_r) + r_child->rangeSumQuery(cur_l, cur_r);
    }

    lng getRange() {
        return r - l + 1;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    vector<int> H(n);
    for (int &h : H)
        cin >> h;

    vector<int> D(n);
    for (int i = 0; i < n; i++)
        D[i] = A[i] - H[i];
    
    SegTree *segt = new SegTree(0, n - 1, D);
    for (int i = 0; i < n - k + 1; i++) {
        lng cur = segt->rangeMinQuery(i, i + k - 1);
        segt->rangeAddUpdate(i, i + k - 1, -cur);
    }

    cout << segt->rangeSumQuery(0, n - 1) << endl;
    
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