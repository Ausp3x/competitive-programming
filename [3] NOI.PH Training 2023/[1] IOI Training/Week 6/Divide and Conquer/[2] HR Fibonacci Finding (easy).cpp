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

int const MOD = 1e9 + 7;

struct Matrix {
    vector<vector<lng>> mtx = {{0, 0}, {0, 0}};

    Matrix operator *(Matrix multiplier) {
        Matrix product = {{{0, 0}, {0, 0}}};
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    product.mtx[i][k] += mtx[i][j] * multiplier.mtx[j][k];
                    product.mtx[i][k] %= MOD;
                }
            }
        }

        return product;
    }
};

Matrix fast_matrix_exp(auto mtx, int n) {
    if (n == 1) {
        return mtx;
    }

    Matrix res = fast_matrix_exp(mtx, n / 2);
    res = res * res;
    if (n % 2 == 1) {
        res = res * mtx;
    }

    return res;
}

int a, b;
int fibonacci(int n) {
    if (n == 0) {
        return a;
    }

    if (n == 1) {
        return b;
    }

    Matrix f = {{{0, 1}, {1, 1}}};
    Matrix f_n = fast_matrix_exp(f, n - 1);
    
    return (f_n.mtx[1][0] * a + f_n.mtx[1][1] * b) % MOD;
}   

void solve() {
    int n;
    cin >> a >> b >> n;

    cout << fibonacci(n) << endl;

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
    cin >> t;
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