// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

vector<vector<lng>> memo;

lng findMaximumSatisfaction(int cur, int vst, int n, int m, vector<vector<lng>> &satisfaction) {
    if (memo[cur][vst] != -1) {
        return memo[cur][vst];
    }
    
    if (m == 0) {
        return 0;
    }

    vst += 1 << cur;

    lng max_satis = 0;
    for (auto nxt = 0; nxt < n; nxt++) {
        if (vst & (1 << nxt)) {
            continue;
        }

        max_satis = max(max_satis, satisfaction[cur][nxt] + findMaximumSatisfaction(nxt, vst, n,  m - 1, satisfaction));
    }

    vst -= 1 << cur;

    memo[cur][vst] = max_satis;
    return memo[cur][vst];
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> as(n);
    for (int &a : as) {
        cin >> a;
    }
    vector<vector<lng>> satisfaction(n, vector<lng>(n));
    while (k--) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        satisfaction[x][y] = c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            satisfaction[i][j] += as[j];
        }
    }

    memo.resize(n, vector<lng>(1 << n, -1));

    lng ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, as[i] + findMaximumSatisfaction(i, 0, n, m - 1, satisfaction));
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