// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

int const MOD = 998244353;

struct Matrix {
    vector<vector<lng>> mtx = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

    Matrix operator *(Matrix multiplier) {
        Matrix product = {{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}};
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    product.mtx[i][k] += mtx[i][j] * multiplier.mtx[j][k];
                    product.mtx[i][k] %= MOD;
                }
            }
        }

        return product;
    }
};

Matrix fast_matrix_pow(auto mtx, int n) {
    if (n == 1) {
        return mtx;
    }

    Matrix res = fast_matrix_pow(mtx, n / 2);
    res = res * res;
    if (n % 2 == 1) {
        res = res * mtx;
    }

    return res;
}

lng fast_mod_pow(lng a, int n) {
    if (n == 0) {
        return 1;
    }
    
    a %= MOD;

    if (a == 0) {
        return 0;
    }

    if (n == 1) {
        return a;
    }

    lng res = fast_mod_pow(a, n / 2);
    (res *= res) %= MOD;
    if (n % 2 == 1) {
        (res *= a) %= MOD;
    }

    return res;
}

void solve() {
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    Matrix t = {{{0, 1, 1, 0}, {w - 1, w - 2, 0, 1}, {h - 1, 0, h - 2, 1}, {0, h - 1, w - 1, w + h - 4}}};
    Matrix t_k = fast_matrix_pow(t, k);

    if (x1 == x2 && y1 == y2) {
        cout << t_k.mtx[0][0] << endl;
    } else if (x1 == x2) {
        cout << t_k.mtx[1][0] * fast_mod_pow(w - 1, MOD - 2) % MOD << endl;
    } else if (y1 == y2) {
        cout << t_k.mtx[2][0] * fast_mod_pow(h - 1, MOD - 2) % MOD << endl;
    } else {
        cout << t_k.mtx[3][0] * fast_mod_pow(1ll * h * w - w - h + 1, MOD - 2) % MOD << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}