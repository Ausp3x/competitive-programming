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

lng modPow(lng x, int y, int MOD) {
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
    int n, k;
    cin >> n >> k;
    vector<int> dst(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> dst[i];

    vector<bool> vst(n + 1);
    vector<vector<vector<int>>> cyc(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vst[i])
            continue;
        
        int j = i;
        vector<int> c;
        do {
            vst[j] = true;
            c.pb(j);
            j = dst[j];
        } while (j != i);

        cyc[c.size()].pb(c);
    }

    // cout << t << ' ' << "Pass" << endl;

    vector<int> ans(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (cyc[i].empty())
            continue;

        int len = cyc[i].size(), q = 0; 
        while (len % 2 == 0) {
            q++;
            len /= 2;
        }

        if (i % 2 == 0 && q < k) {
            cout << "NO" << endl;
            return;
        }

        if (i % 2 == 0) {
            queue<vector<int>> cur_cycs;
            for (auto x : cyc[i])
                cur_cycs.push(x);
        
            int ii = i;
            for (int j = 0; j < k; j++) {
                while (cur_cycs.front().size() == ii) {
                    vector<int> c1 = cur_cycs.front();
                    cur_cycs.pop();
                    vector<int> c2 = cur_cycs.front();
                    cur_cycs.pop();

                    vector<int> nc;
                    for (int l = 0; l < ii; l++) {
                        nc.pb(c1[l]);
                        nc.pb(c2[l]);
                    }

                    cur_cycs.push(nc);
                }

                ii *= 2;
            }

            while (!cur_cycs.empty()) {
                vector<int> c = cur_cycs.front();
                cur_cycs.pop();

                for (int j = 0; j < ii; j++)
                    ans[c[j]] = c[(j + 1) % ii];
            }
        } else {
            int j = 0;
            while (j < cyc[i].size()) {
                q = 0;
                while ((1 << (q + 1)) <= cyc[i].size() - j)
                    q++;

                int d = 1 << q;
                queue<vector<int>> cur_cycs;
                for (int l = j; l < j + d; l++) {
                    vector<int> pc;
                    for (int m = 0; m < i; m++)
                        pc.pb(cyc[i][l][m * modPow((i + 1) / 2, max(k - q, 0), i) % i]);
                    
                    cur_cycs.push(pc);
                }

                int ii = i;
                for (int l = 0; l < min(q, k); l++) {
                    while (cur_cycs.front().size() == ii) {
                        vector<int> c1 = cur_cycs.front();
                        cur_cycs.pop();
                        vector<int> c2 = cur_cycs.front();
                        cur_cycs.pop();

                        vector<int> nc;
                        for (int m = 0; m < ii; m++) {
                            nc.pb(c1[m]);
                            nc.pb(c2[m]);
                        }

                        cur_cycs.push(nc);
                    }

                    ii *= 2;
                }

                while (!cur_cycs.empty()) {
                    vector<int> c = cur_cycs.front();
                    cur_cycs.pop();

                    for (int l = 0; l < ii; l++)
                        ans[c[l]] = c[(l + 1) % ii];
                }

                j += d;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;
    
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