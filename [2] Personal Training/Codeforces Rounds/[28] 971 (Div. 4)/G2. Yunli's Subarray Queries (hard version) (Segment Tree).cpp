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

struct SegTree {    
    int l, r;
    lng mn = INF64;
    vector<lng> C, C_sum;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            mn = arr[l];
            C = {INF64, arr[l]};
            C_sum = {0, arr[l]};
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
            
            C = l_child->C;
            for (lng &rc : r_child->C) {
                if (rc == INF64)
                    continue;
                
                if (rc >= C.back())
                    C.pb(C.back());
                else
                    C.pb(rc);
            }

            mn = C.back();
        
            C_sum = C;
            C_sum[0] = 0;
            for (int i = 1; i < C_sum.size(); i++)
                C_sum[i] += C_sum[i - 1];
        }
    }

    void rangeSumQuery(int &cur_l, int &cur_r, lng &cur_mn, lng &sum) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        } 
        
        if (cur_l == l && r <= cur_r) {
            int l_end = findLastLargerThanCurMin(cur_mn);
            sum += C_sum.back() - C_sum[l_end] + 1ll * l_end * cur_mn;
        
            cur_l = r + 1;
            cur_mn = min(cur_mn, C.back());
            return;
        }
    
        l_child->rangeSumQuery(cur_l, cur_r, cur_mn, sum);
        r_child->rangeSumQuery(cur_l, cur_r, cur_mn, sum);

        return;
    }

    int findLastLargerThanCurMin(lng cur_mn) {
        int ll = 0, rr = C.size();
        while (rr - ll > 1) {
            int md = (ll + rr) / 2;
            
            if (C[md] > cur_mn)
                ll = md;
            else 
                rr = md;
        }

        return ll;
    }
};

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    map<int, int> cnts;
    set<pair<int, int>> S;
    vector<int> ans(n - k + 2);
    for (int i = 1; i <= k; i++)
        cnts[A[i] - i]++;
    for (auto &[a, b] : cnts)
        S.insert({b, a});
    ans[1] = k - S.rbegin()->first; 
    for (int i = k + 1; i <= n; i++) {
        int l = A[i - k] - i + k, r = A[i] - i;

        if (S.find({cnts[l], l}) != S.end())
            S.erase({cnts[l], l});
        if (S.find({cnts[r], r}) != S.end())
            S.erase({cnts[r], r});

        cnts[l]--;
        cnts[r]++;        

        S.insert({cnts[l], l});
        S.insert({cnts[r], r});

        ans[i - k + 1] = k - S.rbegin()->first;
    }

    SegTree *segt = new SegTree(1, n - k + 1, ans);

    while (q--) {
        int l, r;
        cin >> l >> r;
        r -= k - 1;

        lng cur_mn = INF64;
        lng sum = 0;
        segt->rangeSumQuery(l, r, cur_mn, sum);

        cout << sum << endl;
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