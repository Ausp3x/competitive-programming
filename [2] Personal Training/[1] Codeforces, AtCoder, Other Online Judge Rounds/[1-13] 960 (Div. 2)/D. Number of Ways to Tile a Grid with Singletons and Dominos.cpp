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

int N, M;
vector<int> single_memo;
vector<vector<lng>> memo;

lng covers(int msk1, int msk2) {
    for (int i = M - 1; i >= 0; i--)
        if (!(msk1 & (1 << i)))
            if (msk2 & (1 << i))
                return false;

    return true;
}

lng dp(int row, int msk) {
    if (row == N)
        return msk == (1 << M) - 1;

    if (memo[row][msk] != -1)
        return memo[row][msk];

    lng ttl = 0;
    for (int i = 0; i < (1 << M); i++) {
        if (!covers(msk, i))
            continue;

        int cur_msk = msk ^ i;
        int nxt_msk = ((1 << M) - 1) ^ i;

        int rge = 0;
        lng mul = 1;
        for (int j = M - 1; j >= 0; j--) 
            if (cur_msk & (1 << j))
                rge++;
            else {
                mul *= single_memo[rge];
                rge = 0;
            }
        mul *= single_memo[rge];
        rge = 0;
 
        ttl += dp(row + 1, nxt_msk) * mul;
        // if (row == 0)
        //     cout << i << ' ' << cur_msk << ' ' << nxt_msk << ' ' << memo[row + 1][nxt_msk] * mul << endl;
    }
    
    return memo[row][msk] = ttl;
}

void solve() {    
    cin >> N >> M;

    single_memo.clear();
    single_memo.resize(M + 1);
    single_memo[0] = 1;
    for (int i = 1; i <= M; i++) {
        single_memo[i] += single_memo[i - 1];
        if (i > 1)
            single_memo[i] += single_memo[i - 2];
    }

    // for (int x : single_memo)
    //     cout << x << ' ';
    // cout << endl;

    memo.clear();
    memo.resize(N, vector<lng>(1 << M, -1));

    cout << dp(0, (1 << M) - 1) << endl;

    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < (1 << M); j++)
    //         cout << memo[i][j] << ' ';
    //     cout << endl;
    // }

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