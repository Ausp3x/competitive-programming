// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "railroad.h"
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
// #define DEBUG
typedef long long         lng;
typedef pair<int, int>    pi;
typedef vector<int>       vi;
typedef pair<lng, lng>    pl;
typedef vector<lng>       vl;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

lng plan_roller_coaster(vi s, vi t) {
    int n = s.size();
    
    if (n <= 16) {
        vector<vi> cnts(n + 1);
        for (int i = 0; i < (1 << n); i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    cnt++;

            cnts[cnt].push_back(i);
        }

        vector<vl> dp(1 << n, vl(n, INF64));
        for (int i = 0; i < n; i++) 
            dp[1 << i][i] = 0;
        for (int i = 2; i <= n; i++)
            for (int x : cnts[i])
                for (int j = 0; j < n; j++) {
                    if (!(x & (1 << j)))
                        continue;

                    for (int k = 0; k < n; k++)
                        if ((x & (1 << k)) && k != j)
                            dp[x][j] = min(dp[x][j], dp[x ^ (1 << j)][k] + max(t[k] - s[j], 0));
                }
    
        lng ans = INF64;
        for (int i = 0; i < n; i++)
            ans = min(ans, dp[(1 << n) - 1][i]);
        return ans;
    }
    
    return -1;
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
    }

    return 0;
}
#endif