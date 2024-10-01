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

void solve(int t) {
    int n;
    cin >> n;
    bool is_all_0s_or_neg1s = true;
    bool has_neg1s = false;
    bool subtask_8_chk = true;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if (grid[i][j] != 0 && grid[i][j] != -1)
                is_all_0s_or_neg1s = false;
            has_neg1s |= grid[i][j] == -1;
            if (grid[i][j] == -1 && i == j)
                subtask_8_chk = false;
            else if (grid[i][j] != -1 && i != j)
                subtask_8_chk = false;
        }

    if (n == 2) {
        int path1_has_any = (grid[0][0] == -1) + (grid[1][1] == -1);
        int path1 = 0;
        if (grid[0][0] != -1)
            path1 += grid[0][0];
        if (grid[1][1] != -1)
            path1 += grid[1][1];

        int path2_has_any = (grid[0][1] == -1) + (grid[1][0] == -1);
        int path2 = 0;
        if (grid[0][1] != -1)
            path2 += grid[0][1];
        if (grid[1][0] != -1)
            path2 += grid[1][0];

        // cout << path1 << ' ' << path2 << endl;

        if (path1_has_any && path2_has_any) {
            cout << -1 << endl;
            return;
        }

        if (!path1_has_any && !path2_has_any) {
            cout << (path1 == path2) << endl;
            return;
        }

        if (path1_has_any == 1) {
            cout << (path1 <= path2) << endl;
            return;
        }

        if (path2_has_any == 1) {
            cout << (path2 <= path1) << endl;
            return;
        }

        if (path1_has_any == 2) {
            cout << (path2 + 1) % MOD << endl;
            return;
        }

        if (path2_has_any == 2) {
            cout << (path1 + 1) % MOD << endl;
            return;
        }
    
        cout << "WHAT THE FUCK?!?" << endl;
        return;
    }

    if (is_all_0s_or_neg1s) {
        bool line_neg1s = false;
        for (int i = 0; i < n; i++) {
            bool chk = true;
            for (int j = 0; j < n; j++)
                chk &= grid[i][j] == -1;

            line_neg1s |= chk;        
        }

        for (int j = 0; j < n; j++) {
            bool chk = true;
            for (int i = 0; i < n; i++)
                chk &= grid[i][j] == -1;
            
            line_neg1s |= chk;
        }

        cout << (line_neg1s ? -1 : 1) << endl;
        return;
    }

    if (n <= 8 && !has_neg1s) {
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        // for (int x : p)
        //     cout << x << ' ';
        // cout << endl;

        lng sum = 0;
        for (int i = 0; i < n; i++) {
            sum += grid[i][p[i]];
        }
        while (next_permutation(p.begin(), p.end())) {
            lng cur_sum = 0;
            for (int i = 0; i < n; i++) {
                cur_sum += grid[i][p[i]];
            }
            if (sum != cur_sum) {
                cout << 0 << endl;
                return;
            }
        }

        cout << 1 << endl;
        return;
    }

    if (n <= 80 && !has_neg1s) {
        for (int l = 2; l <= n; l++) {
            // int cnt = 0;
            for (int i = 0; i + l <= n; i++)
                for (int j = 0; j + l <= n; j++) {
                    lng sum1 = 0;
                    for (int i2 = i, j2 = j; i2 < i + l && j2 < j + l; i2++, j2++)
                        sum1 += grid[i2][j2];
                
                    lng sum2 = 0;
                    for (int i2 = i + l - 1, j2 = j; i2 >= i && j2 < j + l; i2--, j2++)
                        sum2 += grid[i2][j2];

                    if (sum1 != sum2) {
                        cout << 0 << endl;
                        return;
                    }
                    // cnt++;
                }
        
            // cout << cnt << endl;
        }
            
        cout << 1 << endl;
        return;
    }

    if (!has_neg1s) {
        for (int i = 1; i < n; i++) {
            int d = grid[i][0] - grid[i - 1][0];
            for (int j = 1; j < n; j++) 
                if (grid[i][j] - grid[i - 1][j] != d) {
                    cout << 0 << endl;
                    return;
                }
        }

        cout << 1 << endl;
        
        return;
    }

    if (subtask_8_chk && grid[0][0] == 0) {
        lng ans = 1;
        for (int i = 1; i < n; i++) {
            ans *= grid[i][i] + 1;
            ans %= MOD;
        }

        cout << ans << endl;
        return;
    }

    if (subtask_8_chk) {
        lng ans = 1;
        for (int i = 0; i < n; i++) {
            ans *= grid[i][i] + 1;
            ans %= MOD;
        }
        lng cur = 1;
        for (int i = 0; i < n; i++) {
            cur *= grid[i][i];
            cur %= MOD;
        }

        cout << (ans - cur + MOD) % MOD << endl;
        return;
    }

    vector<vector<int>> X(n), Y(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] != -1) {
                X[i].pb(j);
                Y[j].pb(i);
            }
    
    bool line_neg1s = false;
    for (int i = 0; i < n; i++) {
        bool chk = true;
        for (int j = 0; j < n; j++)
            chk &= grid[i][j] == -1;

        line_neg1s |= chk;        
    }
    for (int j = 0; j < n; j++) {
        bool chk = true;
        for (int i = 0; i < n; i++)
            chk &= grid[i][j] == -1;
        
        line_neg1s |= chk;
    }

    lng ans = 1, minus = 1;
    vector<bool> X_vst(n), Y_vst(n);
    vector<int> A(n, INF32), B(n, INF32);
    for (int i = 0; i < n; i++) {
        if (X_vst[i])
            continue;
        X_vst[i] = true;
        A[i] = 0;

        int a_max = 0, b_min = INF32;
        queue<tuple<int, int, int>> q;
        for (int nxt : X[i])
            q.push({1, nxt, i});
        while (!q.empty()) {
            auto [grp, cur, prv] = q.front();
            q.pop();

            if (grp == 0) {
                X_vst[cur] = true;

                int a = grid[cur][prv] - B[prv];
                a_max = max(a_max, -a);
                if (A[cur] == INF32) {
                    A[cur] = a;
                } else if (A[cur] != a) {
                    cout << 0 << endl;
                    return;
                }

                for (int nxt : X[cur])
                    if (!Y_vst[nxt])
                        q.push({1, nxt, cur});
            } else if (grp == 1) {
                Y_vst[cur] = true;

                int b = grid[prv][cur] - A[prv];
                b_min = min(b_min, b);
                if (B[cur] == INF32) {
                    B[cur] = b;
                } else if (B[cur] != b) {
                    cout << 0 << endl;
                    return;
                }

                for (int nxt : Y[cur])
                    if (!X_vst[nxt])
                        q.push({0, nxt, cur});
            }
        }

        if (a_max > b_min) {
            cout << 0 << endl;
            return;
        }

        ans *= b_min - a_max + 1;
        ans %= MOD;
        minus *= b_min - a_max;
        minus %= MOD;
    }

    if (line_neg1s) {
        cout << -1 << endl;
        return;
    }

    cout << (ans - minus + MOD) % MOD << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}