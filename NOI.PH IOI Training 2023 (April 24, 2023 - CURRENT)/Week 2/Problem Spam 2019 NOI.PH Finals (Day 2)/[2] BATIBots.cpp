// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define ONLINE_JUDGE
// #define DEBUG

int const MOD = 1e9 + 7;
lng const B_MAX = 1e11;

lng fast_exp(lng x, int y) {
    if (y == 0) {
        return 1;
    }

    if (y == 1) {
        return x;
    }

    lng res = 1;
    while (y > 0) {
        if (y & 1) {
            res *= x;
        }

        y >>= 1;
        x *= x;
    }

    return res;
}

map<lng, bool> is_strong;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<lng>> Mactan(h, vector<lng>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> Mactan[i][j];
        }
    }

    int cnt = 0;
    vector<pair<int, int>> idxs;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (is_strong[Mactan[i][j]]) {
                cnt++;
                idxs.push_back({i, j});
            }
        }
    }
    sort(idxs.begin(), idxs.end());

    vector<int> factors;
    for (int i = 1; i * i <= cnt; i++) {
        if (cnt % i != 0) {
            continue;
        }

        factors.push_back(i);
        if (cnt / i != i) {
            factors.push_back(cnt / i);
        }
    }
    sort(factors.begin(), factors.end());

    int len = factors.size();
    lng ans = 0;
    for (int i = 0; i < len; i++) {
        bool is_pos = true;
        lng cur = 1;
        for (int j = factors[i]; j < cnt; j += factors[i]) {
            if (idxs[j].first == idxs[j - 1].first) {
                is_pos = false;
                break;
            }

            (cur *= idxs[j].first - idxs[j - 1].first) %= MOD;
        }

        if (!is_pos) {
            continue;
        }

        vector<pair<int, int>> col_idx_extremas(factors[i], {1e9, -1e9});
        for (int j = 0; j < cnt; j += factors[i]) {
            vector<int> col_idxs;
            for (int k = j; k < j + factors[i]; k++) {
                col_idxs.push_back(idxs[k].second);
            }
            sort(col_idxs.begin(), col_idxs.end());

            for (int k = 0; k < factors[i]; k++) {
                col_idx_extremas[k].first = min(col_idx_extremas[k].first, col_idxs[k]);
                col_idx_extremas[k].second = max(col_idx_extremas[k].second, col_idxs[k]);
            }
        }

        for (int j = 1; j < factors[i]; j++) {
            if (col_idx_extremas[j].first <= col_idx_extremas[j - 1].second) {
                is_pos = false;
                break;
            }

            (cur *= col_idx_extremas[j].first - col_idx_extremas[j - 1].second) %= MOD;
        }

        if (!is_pos) {
            continue;
        }

        (ans += cur) %= MOD;
    }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

#ifdef DEBUG
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef DEBUG
    // testing code
#endif

    is_strong[1] = true;
    for (lng i = 1; i * i <= B_MAX; i++) {
        for (lng j = 1; i * i * j * j * j <= B_MAX; j++) {
            is_strong[i * i * j * j * j] = true;
        }
    }

    for (lng i = 2; i * i <= B_MAX; i++) {
        for (lng j = 2; fast_exp(i, j) <= B_MAX; j++) {
            lng cur = fast_exp(i, j);

            if (is_strong.count(cur)) {
                is_strong[cur] = false;
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

#ifdef DEBUG
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}