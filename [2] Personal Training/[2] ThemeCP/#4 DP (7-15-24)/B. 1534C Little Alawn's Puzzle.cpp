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

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int MOD = 1000000007;

lng modPow(lng x, int y) {
    lng res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
            res %= MOD;
        }

        y >>= 1;
        x *= x;
        x %= MOD;
    }

    return (res + MOD) % MOD;
}

void solve(int t) {
    int n;
    cin >> n;
    vector<vector<int>> grid(2, vector<int>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    
    vector<int> adjl(n + 1);
    for (int j = 0; j < n; j++)
        adjl[grid[0][j]] = grid[1][j];

    int cyc = 0;
    vector<bool> vst(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vst[i])
            continue;
        cyc++;
        vst[i] = true;

        int j = i;
        do {
            j = adjl[j];
            vst[j] = true;
        } while (j != i);
    }

    cout << modPow(2, cyc) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}