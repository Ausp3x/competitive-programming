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
typedef __int128     lll;
template<class T> 
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int l, n, m;
    cin >> l >> n >> m;
    vector<int> A(l + 1);
    for (int i = 1; i <= l; i++)
        cin >> A[i];
    vector<vector<int>> B(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> B[i][j];

    vector<int> idxs(8);
    for (int i = 1; i <= l; i++) {
        if (idxs[A[i]]) {
            l = i - 1;
            break;
        }

        idxs[A[i]] = i;
    }

    vector<vector<vector<bool>>> dp(8, vector<vector<bool>>(n + 1, vector<bool>(m + 1)));
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            for (int k = 1; k <= l; k++) {
                if (i < n && dp[k][i + 1][j]) {
                    dp[k][i][j] = true;
                    continue;
                }

                if (j < m && dp[k][i][j + 1]) {
                    dp[k][i][j] = true;
                    continue;
                }

                if (B[i][j] == A[k]) {
                    if (k == l) {
                        dp[k][i][j] = true;
                    } else if (i < n && j < m) {
                        dp[k][i][j] = !dp[k + 1][i + 1][j + 1];
                    } else {
                        dp[k][i][j] = true;
                    }
                } else
                    dp[k][i][j] = false;
            }

    cout << (dp[1][1][1] ? 'T' : 'N') << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}