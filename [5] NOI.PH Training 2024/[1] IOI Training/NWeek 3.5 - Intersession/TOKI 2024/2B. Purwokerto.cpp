// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "purwokerto.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long    lng;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int const MOD = 1000000007;

/*
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

vector<lng> fac;
vector<lng> inv_fac;

lng choose(int n, int k) {
    if (k > n)
        return 0;
    
    return fac[n] * inv_fac[k] % MOD * inv_fac[n - k] % MOD; 
}
//*/

pair<lng, int> purwokerto(int N, int M, vector<int> T) {
    if (N == 1) {
        lng coins = 0, ways = 1;

        int cur = 0, l = -1, r = -1;
        for (int i = 0; i < M; i++) {
            if (T[i] == cur) {
                if (l == -1)
                    l = r = i;
                else
                    r = i;
            } else {
                if (l == -1)
                    continue;

                if (cur == 0) {
                    ways *= (r - l + 1);
                    ways %= MOD;
                } else {
                    coins++;
                    ways *= (r - l + 1);
                    ways %= MOD;
                }

                cur ^= 1;
                l = i;
                r = i;
            }
        }
        if (cur == 1) {
            coins++;
            ways *= (r - l + 1);
            ways %= MOD;
        }

        return {coins, ways};
    }

    //*
    if (N <= 11 && M <= 2000) {
        // coins, ways
        vector<vector<pair<lng, lng>>> dp(M + 1, vector<pair<lng, lng>>(1 << N, {-1, -1}));
        dp[0][0] = {0, 1};
        for (int i = 0; i < M; i++) {
            if (T[i] == 0) {
                for (int cur_msk = 0; cur_msk < (1 << N); cur_msk++) {
                    if (dp[i][cur_msk].fi == -1)
                        continue;
                    
                    if (dp[i + 1][cur_msk].fi < dp[i][cur_msk].fi)
                        dp[i + 1][cur_msk] = dp[i][cur_msk];
                    else if (dp[i + 1][cur_msk].fi == dp[i][cur_msk].fi) {
                        dp[i + 1][cur_msk].se += dp[i][cur_msk].se;
                        dp[i + 1][cur_msk].se %= MOD;
                    }
                    for (int j = 0; j < N; j++) { 
                        if (cur_msk & (1 << j))
                            continue;

                        int nxt_msk = cur_msk ^ (1 << j);
                        if (dp[i + 1][nxt_msk].fi < dp[i][cur_msk].fi) 
                            dp[i + 1][nxt_msk] = dp[i][cur_msk];  
                        else if (dp[i + 1][nxt_msk].fi == dp[i][cur_msk].fi) {
                            dp[i + 1][nxt_msk].se += dp[i][cur_msk].se;
                            dp[i + 1][nxt_msk].se %= MOD;
                        }
                    }
                }
            } else if (T[i] == 1) {
                for (int cur_msk = 0; cur_msk < (1 << N); cur_msk++) {
                    if (dp[i][cur_msk].fi == -1)
                        continue;

                    if (dp[i + 1][cur_msk].fi < dp[i][cur_msk].fi)
                        dp[i + 1][cur_msk] = dp[i][cur_msk];
                    else if (dp[i + 1][cur_msk].fi == dp[i][cur_msk].fi) {
                        dp[i + 1][cur_msk].se += dp[i][cur_msk].se;
                        dp[i + 1][cur_msk].se %= MOD;
                    }
                    for (int j = 0; j < N; j++) { 
                        if (!(cur_msk & (1 << j)))
                            continue;
                
                        int nxt_msk = cur_msk ^ (1 << j);
                        if (dp[i + 1][nxt_msk].fi < dp[i][cur_msk].fi + j + 1) {
                            dp[i + 1][nxt_msk] = dp[i][cur_msk];
                            dp[i + 1][nxt_msk].fi += j + 1;
                            continue;
                        }

                        if (dp[i + 1][nxt_msk].fi == dp[i][cur_msk].fi + j + 1) {
                            dp[i + 1][nxt_msk].se += dp[i][cur_msk].se;
                            dp[i + 1][nxt_msk].se %= MOD;
                        }
                    }
                }
            }
        }

        // for (int i = 0; i <= M; i++) {
        //     for (int j = 0; j < (1 << N); j++)
        //         cout << dp[i][j].fi << ' ';
        //     cout << endl;
        // }

        return {dp[M][0].fi, dp[M][0].se};
    }
    //*/
    
    /*
    fac.clear();
    fac.resize(M + 1);
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i <= M; i++)
        fac[i] = fac[i - 1] * i % MOD;
    
    inv_fac.clear();
    inv_fac.resize(M + 1);
    for (int i = 0; i <= M; i++)
        inv_fac[i] = modPow(fac[i], MOD - 2);

    for (int i = 0; i <= min(N, 10); i++)
        cout << fac[i] << ' ';
    cout << endl;
    for (int i = 0; i <= min(N, 10); i++)
        cout << inv_fac[i] << ' ';
    cout << endl;
    cout << endl;
    //*/

    int cur = -1;
    deque<pair<int, int>> dq;
    for (int i = 0; i < M; i++) {
        if (T[i] == cur)
            dq.back().se++;
        else {
            cur = T[i];
            dq.pb({T[i], 1});
        }
    }

    // for (auto [x, y] : dq)
    //     cout << x << ' ' << y << endl;
    // cout << endl;

    lng coins = 0, ways = 1;
    for (int i = N; i >= 1; i--) {
        while (!dq.empty() && dq.front().fi == 1)
            dq.pop_front();    
        while (!dq.empty() && dq.back().fi == 0)
            dq.pop_back();
    
        coins += 1ll * i * (dq.size() / 2);
        for (auto &[cur, cnt] : dq) {
            // cout << i << ' ' << cur << ' ' << cnt << endl;
            ways *= cnt;
            ways %= MOD;
            cnt--;
        }

        deque<pair<int, int>> new_dq;
        for (auto [cur, cnt] : dq) {
            if (cnt == 0)
                continue;

            if (!new_dq.empty())
                if (new_dq.back().fi == cur) {
                    new_dq.back().se += cnt;
                    continue;
                }

            new_dq.pb({cur, cnt});
        }
        dq = new_dq;
    }

    return {coins, ways};   
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> T(M);
        for (int &tt : T)
            cin >> tt;

        pair<lng, int> ans = purwokerto(N, M, T);
        cout << ans.fi << ' ' << ans.se << endl;
    }

    return 0;
}
#endif