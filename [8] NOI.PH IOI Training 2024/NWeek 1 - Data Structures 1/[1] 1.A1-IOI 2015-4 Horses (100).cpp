// 人外有人，天外有天
// author: Ausp3x
 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "horses.h"
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;
 
int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;
 
int const MOD = 1000000007;

int nextPowOf2(int n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;

    return n;
}

int N;
vector<int> X, Y;

int N2;
// actual prod, modulo prod
vector<pair<lng, lng>> x_seg;  
vector<int> i_seg;

lng queryXSeg(int l, int r, int opt) {
    l += N2;
    r += N2;

    lng res = 1;
    if (opt == 1) {
        while (l <= r) {
            if (l & 1) {
                res *= x_seg[l++].first;
                if (res > INF32)
                    res = INF32;
            } 
            if (!(r & 1)) {
                res *= x_seg[r--].first;
                if (res > INF32)
                    res = INF32;
            }

            l >>= 1;
            r >>= 1;
        }
    } else if (opt == 2) {
        while (l <= r) {
            if (l & 1)
                (res *= x_seg[l++].second) %= MOD;
            if (!(r & 1))
                (res *= x_seg[r--].second) %= MOD;

            l >>= 1;
            r >>= 1;
        }
    }

    return res;
}

void updateISeg(int i) {
    (i += N2) >>= 1;
    while (i > 0) {
        if (i_seg[2 * i + 1] == -1)
            i_seg[i] = i_seg[2 * i];
        else {
            if (Y[i_seg[2 * i]] >= queryXSeg(i_seg[2 * i] + 1, i_seg[2 * i + 1], 1) * Y[i_seg[2 * i + 1]])
                i_seg[i] = i_seg[2 * i];
            else
                i_seg[i] = i_seg[2 * i + 1];
        }

        i >>= 1;
    }

    return;
}

int init(int n, int x[], int y[]) {
    N = n;
    X.clear();
    X.resize(N);
    Y.clear();
    Y.resize(N);
    for (int i = 0; i < N; i++) {
        X[i] = x[i];
        Y[i] = y[i];
    }
    
    N2 = nextPowOf2(N);
    x_seg.clear();
    x_seg.resize(2 * N2, {-1, -1});
    for (int i = N2; i < N2 + N; i++) {
        x_seg[i].first = X[i - N2];
        x_seg[i].second = X[i - N2];
    }
    for (int d = N2 / 2; d >= 1; d >>= 1)
        for (int i = d; i < 2 * d; i++) {
            if (x_seg[2 * i + 1].first == -1)
                x_seg[i] = x_seg[2 * i];
            else {
                x_seg[i].first = x_seg[2 * i].first * x_seg[2 * i + 1].first;
                if (x_seg[i].first > INF32)
                    x_seg[i].first = INF32;
                (x_seg[i].second = x_seg[2 * i].second * x_seg[2 * i + 1].second) %= MOD;
            }
        }
    
    // for (auto [x, y] : x_seg)
    //     cout << x << ' ';
    // cout << endl;
    // for (auto [x, y] : x_seg)
    //     cout << y << ' ';
    // cout << endl;
    
    i_seg.clear();
    i_seg.resize(2 * N2, -1);
    for (int i = N2; i < N2 + N; i++)
        i_seg[i] = i - N2;
    for (int d = N2 / 2; d >= 1; d >>= 1)
        for (int i = d; i < 2 * d; i++) {
            if (i_seg[2 * i + 1] == -1)
                i_seg[i] = i_seg[2 * i];
            else {
                if (Y[i_seg[2 * i]] >= queryXSeg(i_seg[2 * i] + 1, i_seg[2 * i + 1], 1) * Y[i_seg[2 * i + 1]])
                    i_seg[i] = i_seg[2 * i];
                else
                    i_seg[i] = i_seg[2 * i + 1];
            }
        }
    
    // for (int x : i_seg)
    //     cout << x << ' ';
    // cout << endl;

    return queryXSeg(0, i_seg[1], 2) * Y[i_seg[1]] % MOD;
}

int updateX(int i, int v) {
    X[i] = v;

    int ii = i + N2;
    x_seg[ii] = {v, v};
    ii >>= 1;
    while (ii > 0) {
        if (x_seg[2 * ii + 1].first == -1)
            x_seg[ii] = x_seg[2 * ii];
        else {
            x_seg[ii].first = x_seg[2 * ii].first * x_seg[2 * ii + 1].first;
            if (x_seg[ii].first > INF32)
                x_seg[ii].first = INF32;
            (x_seg[ii].second = x_seg[2 * ii].second * x_seg[2 * ii + 1].second) %= MOD;
        }

        ii >>= 1;
    }

    updateISeg(i);

    return queryXSeg(0, i_seg[1], 2) * Y[i_seg[1]] % MOD;
}

int updateY(int i, int v) {
    Y[i] = v;

    updateISeg(i);

    return queryXSeg(0, i_seg[1], 2) * Y[i_seg[1]] % MOD;
}

/*
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        int y[n];
        for (int i = 0; i < n; i++) {
            cin >> y[i];
        }

        cout << init(n, x, y) << endl;

        int m;
        cin >> m;
        while (m--) {
            int opt, pos, val;
            cin >> opt >> pos >> val;
            if (opt == 1) {
                cout << opt << ' ' << pos << ' ' << val << ' ';
                cout << updateX(pos, val) << endl;
            } else if (opt == 2) {
                cout << opt << ' ' << pos << ' ' << val << ' ';
                cout << updateY(pos, val) << endl;
            }
        }
    }

    return 0;
}
//*/