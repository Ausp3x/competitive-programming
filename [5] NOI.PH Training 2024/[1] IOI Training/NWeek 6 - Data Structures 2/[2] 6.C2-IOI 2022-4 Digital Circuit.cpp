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
#include "circuit.h"
#endif
typedef long long    lng;
typedef __int128     lll;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng N, M;
vector<int> P;
vector<lng> A;
vector<vector<int>> adjl;

struct ModInt {
    lng const MOD = 1'000'002'022;
    lng const PHI_MOD = 497'758'632;
    lng exp_2 = 0, exp_223 = 0, rem = 0;

    void init(lng x) {
        while (x % 2 == 0 && x > 0) {
            exp_2++;
            x /= 2;
        }

        while (x % 223 == 0 && x > 0) {
            exp_223++;
            x /= 223;
        }

        rem = x % MOD;
    }

    void copy(ModInt const &x) {
        exp_2 = x.exp_2;
        exp_223 = x.exp_223;
        rem = x.rem;
    }

    void multiplyBy(ModInt const &x) {
        exp_2 += x.exp_2;
        exp_223 += x.exp_223;
        rem *= x.rem;
        rem %= MOD;

        return;
    }

    // only works when divisible by x
    void divideBy(ModInt const &x) {
        assert(exp_2 >= x.exp_2);
        assert(exp_223 >= x.exp_223);

        exp_2 -= x.exp_2;
        exp_223 -= x.exp_223;
        rem *= modPow(x.rem, PHI_MOD - 1, MOD);
        rem %= MOD;
    
        return;
    }

    lng getValue() {
        return modPow(2, exp_2, MOD) * modPow(223, exp_223, MOD) % MOD * rem % MOD;
    }
    
    lng modPow(lng x, lng y, lng mod) {
        lng res = 1;
        while (y > 0) {
            if (y & 1) {
                res *= x;
                res %= mod;
            }

            y >>= 1;
            x *= x;
            x %= mod;
        }

        return (res + mod) % mod;
    }
};

struct SegTree {
    lng const MOD = 1'000'002'022;
    int l, r;
    lng ttl = 0; // must be constant after initialization
    lng sum = 0, upd = 0;
    SegTree *l_child, *r_child;

    template<class T> 
    SegTree(int l, int r, const vector<T> &arr): l(l), r(r) {
        if (l == r) {
            ttl = arr[l];
            sum = arr[l];
            l_child = r_child = nullptr;
        } else {
            int m = (l + r) / 2;
            l_child = new SegTree(l, m, arr);
            r_child = new SegTree(m + 1, r, arr);
            ttl = (l_child->ttl + r_child->ttl) % MOD;
            sum = (l_child->sum + r_child->sum) % MOD;
        }
    }

    // push updates down to children
    void push() {
        if (l_child != nullptr && r_child != nullptr) {
            l_child->upd += upd;
            l_child->upd %= 2;
            if (upd)
                l_child->reverseSum();
            r_child->upd += upd;
            r_child->upd %= 2;
            if (upd)
                r_child->reverseSum();
            upd = 0;
        }

        return;
    }

    // pull states up from children
    void pull() {
        assert(upd == 0);
        if (l_child != nullptr && r_child != nullptr) {
            sum = (l_child->sum + r_child->sum) % MOD;
        }

        return;
    }

    void rangeSumUpdate(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return;
        }

        if (cur_l <= l && r <= cur_r) {
            upd++;
            upd %= 2;
            reverseSum();
            return;
        }
        
        push();
        l_child->rangeSumUpdate(cur_l, cur_r);
        r_child->rangeSumUpdate(cur_l, cur_r);
        pull();
        return;
    }

    lng rangeSumQuery(int cur_l, int cur_r) {
        if (cur_l > cur_r || (r < cur_l || cur_r < l)) {
            return 0;
        } 
        
        if (cur_l <= l && r <= cur_r) {
            return sum;
        }
        
        push();
        return (l_child->rangeSumQuery(cur_l, cur_r) + r_child->rangeSumQuery(cur_l, cur_r)) % MOD;
    }

    void reverseSum() {
        sum = (ttl - sum + MOD) % MOD;
    }

    void debugPrint(int depth = 0) {
        for (int t = 0; t < depth; t++) {
            cout << '\t';
        }
        cout << "[" << l << ", " << r << "] has ttl " << ttl << ", has sum " << sum << ", and upd " << upd << endl;
        if (l_child != nullptr && r_child != nullptr) {
            l_child->debugPrint(depth + 1);
            r_child->debugPrint(depth + 1);
        }

        return;
    }
};

vector<ModInt> W;
void initW(int cur, int prv) {
    if (cur >= N)
        return;

    W[cur].init(adjl[cur].size() - (cur != 0));
    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        initW(nxt, cur);

        W[cur].multiplyBy(W[nxt]);
    }

    return;
}

vector<ModInt> C;
void initC(int cur, int prv) {
    ModInt cnt;
    cnt.init(adjl[cur].size() - (cur != 0));
    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        C[nxt].copy(C[cur]);
        C[nxt].divideBy(cnt);

        initC(nxt, cur);
    }
    
    return;
}

SegTree *segt = nullptr;
void init(int _N, int _M, vector<int> _P, vector<int> _A) {
    N = _N;
    M = _M;
    P.clear();
    P.resize(N + M);
    for (int i = 0; i < N + M; i++)
        P[i] = _P[i];
    A.clear();
    A.resize(M);
    for (int i = 0; i < M; i++)
        A[i] = _A[i];

    adjl.clear();
    adjl.resize(N + M);
    for (int i = 1; i < N + M; i++) {
        adjl[P[i]].pb(i);
        adjl[i].pb(P[i]);
    }

    W.clear();
    W.resize(N + M);
    for (int i = 0; i < N + M; i++)
        W[i].init(1);
    initW(0, 0);

    C.clear();
    C.resize(N + M);
    C[0].copy(W[0]);
    initC(0, 0);

    vector<lng> C_ints(M);
    for (int i = 0; i < M; i++) 
        C_ints[i] = C[i + N].getValue();

    segt = new SegTree(0, M - 1, C_ints);
    for (int i = 0; i < M; i++)
        if (!A[i])
            segt->rangeSumUpdate(i, i);

    // segt->debugPrint();

    return;
}

int count_ways(int L, int R) {
    L -= N;
    R -= N;
    segt->rangeSumUpdate(L, R);
    // segt->debugPrint();

    return segt->rangeSumQuery(0, M - 1);
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        int _N, _M, Q;
        cin >> _N >> _M >> Q;
        vector<int> _P(_N + _M);
        for (int &p : _P)
            cin >> p;
        vector<int> _A(_M);
        for (int &a : _A)
            cin >> a;

        init(_N, _M, _P, _A);

        while (Q--) {
            int L, R;
            cin >> L >> R;

            cout << count_ways(L, R) << endl; 
        }
    }

    return 0;
}
#endif