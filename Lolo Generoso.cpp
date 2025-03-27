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
    int mn_idx = -1, mx_idx = -1;
    lng add_upd = 0, set_upd = 0;
    bool set_flag = false;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            assert(-INF64 < arr[l] && arr[l] < INF64);
            mn = mx = sum = arr[l];
            mn_idx = mx_idx = l;
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
                l_child->mn_idx = l_child->mx_idx = l_child->l;
                
                r_child->add_upd = 0;
                r_child->set_upd = set_upd;
                r_child->set_flag = true;
                r_child->mn = r_child->mx = set_upd;
                r_child->sum = r_child->getRange() * set_upd;
                r_child->mn_idx = r_child->mx_idx = r_child->l;
                
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
            if (l_child->mn <= r_child->mn) {
                mn = l_child->mn;
                mn_idx = l_child->mn_idx;
            } else {
                mn = r_child->mn;
                mn_idx = r_child->mn_idx;
            }

            if (l_child->mx >= r_child->mx) {
                mx = l_child->mx;
                mx_idx = l_child->mx_idx;
            } else {
                mx = r_child->mx;
                mx_idx = r_child->mx_idx;
            }

            sum = l_child->sum + r_child->sum;
        }

        return;
    }

    void rangeAddUpdate(int cur_l, int cur_r, lng x) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }
        
        if (cur_l <= l && r <= cur_r) {
            if (set_flag) {
                set_upd += x;
            } else { 
                add_upd += x; 
            }
            mn += x;
            mx += x;
            sum += getRange() * x;            
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
            mn = mx = x;
            sum = getRange() * x;
            mn_idx = mx_idx = l;
            return;
        }
        
        push();
        l_child->rangeSetUpdate(cur_l, cur_r, x);
        r_child->rangeSetUpdate(cur_l, cur_r, x);
        pull();

        return;
    }

    pair<lng, int> rangeMaxQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return {-INF64, -1};
        }

        if (cur_l <= l && r <= cur_r) {
            return {mx, mx_idx};
        }
        
        push();
        auto l_res = l_child->rangeMaxQuery(cur_l, cur_r);
        auto r_res = r_child->rangeMaxQuery(cur_l, cur_r);
        if (l_res.fi >= r_res.fi) {
            return l_res;
        } else {
            return r_res;
        }
    }

    pair<lng, int> rangeMinQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return {INF64, -1};
        }

        if (cur_l <= l && r <= cur_r) {
            return {mn, mn_idx};
        }
        
        push();
        auto l_res = l_child->rangeMinQuery(cur_l, cur_r);
        auto r_res = r_child->rangeMinQuery(cur_l, cur_r);
        if (l_res.fi <= r_res.fi) {
            return l_res;
        } else {
            return r_res;
        }
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

struct EulerTourTree {
    int n, root;
    vector<lng> arr;
    vector<vector<int>> adjl;

    int timer = 0;
    vector<int> t_in, t_out, time_to_orig;
    vector<lng> euler;
    SegTree *segt;

    template<class T>
    EulerTourTree(int n, int root, const vector<T> &arr, const vector<vector<T>> &adjl) : n(n), root(root), arr(arr), adjl(adjl) {
        assert(0 <= root && root < n);
        assert(arr.size() == n && adjl.size() == n);
        t_in.resize(n);
        t_out.resize(n);
        time_to_orig.resize(n);
        euler.resize(n);
        
        dfs(root, -1);

        segt = new SegTree(0, n - 1, euler);
    }

    void dfs(int cur, int prv) {
        t_in[cur] = timer;
        time_to_orig[timer] = cur;
        euler[timer] = arr[cur];
        timer++;
        for (int nxt : adjl[cur]) {
            if (nxt == prv)
                continue;

            dfs(nxt, cur);
        }
        t_out[cur] = timer - 1;

        return;
    }

    void subtreeAddUpdate(int u, lng x, bool u_only = false) {
        segt->rangeAddUpdate(t_in[u], (u_only ? t_in[u] : t_out[u]), x);
    }

    void subtreeSetUpdate(int u, lng x, bool u_only = false) {
        segt->rangeSetUpdate(t_in[u], (u_only ? t_in[u] : t_out[u]), x);
    }

    pair<lng, int> subtreeMaxQuery(int u, bool u_only = false) {
        auto res = segt->rangeMaxQuery(t_in[u], (u_only ? t_in[u] : t_out[u]));
        res.se = time_to_orig[res.se];

        return res;
    }
    
    pair<lng, int> subtreeMinQuery(int u, bool u_only = false) {
        auto res = segt->rangeMinQuery(t_in[u], (u_only ? t_in[u] : t_out[u]));
        res.se = time_to_orig[res.se];

        return res;
    }

    lng subtreeSumQuery(int u, bool u_only = false) {
        return segt->rangeSumQuery(t_in[u], (u_only ? t_in[u] : t_out[u]));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    map<string, int> name_to_idx = {{"GENEROSO", 0}};
    vector<string> idx_to_name = {"GENEROSO"};
    vector<lng> wealth = {INF64};
    for (int i = 1; i <= n; i++) {
        string s;
        int w;
        cin >> s >> w;
        
        name_to_idx[s] = i;
        idx_to_name.pb(s);
        wealth.pb(w);
    }
    vector<vector<int>> adjl(name_to_idx.size());
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;


    }
    
    string x, y;
    while (cin >> x >> y) {
        if (x == "INC") {
            lng w;
            cin >> w;


        }
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