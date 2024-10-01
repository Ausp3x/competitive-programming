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
#ifndef DEBUG
#include "overtaking.h"
#endif
typedef long long    lng;
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

struct SegTree {    
    lng yl, yr;
    SegTree *l_child = nullptr, *r_child = nullptr;

    lng zl, zr, upd = 0;
 
    SegTree(lng yl, lng yr, lng zl, lng zr): yl(yl), yr(yr), zl(zl), zr(zr) {};

    void push() {
        if (l_child != nullptr && r_child != nullptr) {
            l_child->zl += upd;
            l_child->zr += upd;
            l_child->upd += upd;
            r_child->zl += upd;
            r_child->zr += upd;
            r_child->upd += upd;
        }
        upd = 0;

        return;
    }

    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            zl = l_child->zl;
            zr = r_child->zr;
        }

        return;
    }

    void createChildren() {
        if (l_child == nullptr && r_child == nullptr) {
            if (yr - yl != zr - zl) {
                return;
            }

            lng ym = (yl + yr) / 2;
            l_child = new SegTree(yl, ym, zl, zl + ym - yl);
            r_child = new SegTree(ym + 1, yr, zl + ym - yl + 1, zr);
        }

        return;
    }

    void deleteChildren() {
        delete l_child;
        l_child = nullptr;
        delete r_child;
        r_child = nullptr;

        return;
    }

    void rangeAdd(lng cur_zl, lng cur_zr, lng t) {
        if (cur_zl > cur_zr || (zr < cur_zl || cur_zr < zl)) {
            return;
        }

        if (cur_zl <= zl && zr <= cur_zr) {
            zl += t;
            zr += t;
            upd += t;
            return;
        }
        
        push();
        createChildren();
        l_child->rangeAdd(cur_zl, cur_zr, t);
        r_child->rangeAdd(cur_zl, cur_zr, t);
        pull();

        return;
    }

    // for this function to work
    // 1) ranges must NOT overlap
    // 2) ranges must be done last to first
    void rangeFix(lng cur_zl, lng cur_zr, lng z) {
        if (cur_zl > cur_zr || (zr < cur_zl || cur_zr < zl)) {
            return;
        }

        if (cur_zl <= zl && zr <= cur_zr) {
            zl = z;
            zr = z;
            deleteChildren();
            return;
        }
        
        push();
        createChildren();
        l_child->rangeFix(cur_zl, cur_zr, z);
        r_child->rangeFix(cur_zl, cur_zr, z);
        pull();

        return;
    }

    lng singleQuery(lng y) {
        assert(yl <= y && y <= yr);
        if (l_child == nullptr && r_child == nullptr) {
            // cout << yl << ' ' << yr << ' '<< zl << ' ' << zr << ' ';
            if (zl == zr) {
                return zl;
            } else if (yr - yl == zr - zl) {
                return zl + y - yl;
            }
            return -1;
        }

        push();
        if (l_child->yl <= y && y <= l_child->yr) {
            return l_child->singleQuery(y);
        } else if (r_child->yl <= y && y <= r_child->yr) {
            return r_child->singleQuery(y);
        }

        return -1;
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << yl << ", " << yr << "] has [" << zl << ", " << zr << "] and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

// lng Y_MAX = 1'005;
lng Y_MAX = 1'000'000'000'000'000'005;
SegTree *segt = new SegTree(0, Y_MAX, 0, Y_MAX);

void init(int L, int N, vector<lng> T, vector<int> W, int X, int M, vector<int> S) {
    vector<int> buses_slower_than_reserve;
    // time bus i arrives at station j
    vector<vector<lng>> arrival_times(N, vector<lng>(M));
    for (int i = 0; i < N; i++) {
        if (W[i] > X)
            buses_slower_than_reserve.pb(i);
        arrival_times[i][0] = T[i];
    } 
    for (int j = 1; j < M; j++) {
        map<lng, set<pair<lng, int>>> sorted_arrival_times;
        for (int i = 0; i < N; i++)
            sorted_arrival_times[arrival_times[i][j - 1]].insert({arrival_times[i][j - 1] + 1ll * W[i] * (S[j] - S[j - 1]), i});

        lng t = 0; 
        for (auto &[t_prv, S] : sorted_arrival_times) {
            lng e_max = 0;
            for (auto &[e, i] : S) {
                arrival_times[i][j] = max(t, e);
                e_max = max(e_max, e);
            }

            t = max(t, e_max);
        }
    }

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++)
    //         cout << arrival_times[i][j] << ' ';
    //     cout << endl;
    // }
    // cout << endl;

    lng offset = 0;
    for (int j = 1; j < M; j++) {
        segt->rangeAdd(offset, Y_MAX + offset, 1ll * X * (S[j] - S[j - 1]));
        // segt->debugPrint();
        // cout << endl;

        vector<tuple<lng, lng, lng>> V;
        for (int i : buses_slower_than_reserve)
            V.pb({arrival_times[i][j] + 1ll * (X - W[i]) * (S[j] - S[j - 1]) + 1, arrival_times[i][j], arrival_times[i][j]});

        sort(V.begin(), V.end());

        // for (auto &[cur_zl, cur_zr, z] : V) 
        //     cout << cur_zl << ' ' << cur_zr << ' ' << z << endl;
        // cout << endl;
        
        vector<tuple<lng, lng, lng>> V_pruned;
        if (!V.empty()) {
            V_pruned.pb(V[0]);
            for (int i = 1; i < V.size(); i++)
                if (get<2>(V[i]) > get<2>(V_pruned.back()))
                    V_pruned.pb(V[i]);
        }

        for (int i = 1; i < V_pruned.size(); i++)
            get<1>(V_pruned[i - 1]) = min(get<1>(V_pruned[i - 1]), get<0>(V_pruned[i]) - 1);

        // for (auto &[cur_zl, cur_zr, z] : V_pruned) 
        //     cout << cur_zl << ' ' << cur_zr << ' ' << z << endl;
        // cout << endl;

        reverse(V_pruned.begin(), V_pruned.end());

        for (auto [cur_zl, cur_zr, z] : V_pruned) {
            if (cur_zl > cur_zr)
                continue;

            // cout << cur_zl << ' ' << cur_zr << ' ' << z << endl;
            
            segt->rangeFix(cur_zl, cur_zr, z);
            // segt->debugPrint();
            // cout << endl;
        }
        
        offset += 1ll * X * (S[j] - S[j - 1]);
    }

    return;
}

lng arrival_time(lng Y) {
    return segt->singleQuery(Y);
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        int L, N, X, M, Q;
        cin >> L >> N >> X >> M >> Q;
        vector<lng> T(N);
        for (lng &t : T)
            cin >> t;
        vector<int> W(N);
        for (int &w : W)
            cin >> w;
        vector<int> S(M);
        for (int &s : S)
            cin >> s;

        init(L, N, T, W, X, M, S);

        while (Q--) {
            int Y;
            cin >> Y;
            
            cout << arrival_time(Y) << endl;
        }
    }

    return 0;
}
#endif