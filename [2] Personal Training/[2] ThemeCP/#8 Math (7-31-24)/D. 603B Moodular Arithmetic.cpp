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

void solve() {
    lng p, k;
    cin >> p >> k;
    
    if (k == 0) {
        lng ans = 1;
        for (int i = 1; i < p; i++) {
            ans *= p;
            ans %= MOD;
        }

        cout << ans << endl;
        return;
    }

    if (k == 1) {
        lng ans = 1;
        for (int i = 0; i < p; i++) {
            ans *= p;
            ans %= MOD;
        }

        cout << ans << endl;
        return;
    }

    vector<vector<int>> adjl(p);
    for (int i = 1; i < p; i++) {
        adjl[i].pb(k * i % p);
        adjl[k * i % p].pb(i);
    }

    lng ans = 1;
    vector<bool> vst(p);
    for (int i = 1; i < p; i++) {
        if (vst[i])
            continue;

        ans *= p;
        ans %= MOD;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (vst[cur])
                continue;
            vst[cur] = true;

            for (int nxt : adjl[cur])
                if (!vst[nxt])
                    q.push(nxt);
        }
    }

    cout << ans << endl;
    
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