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

void solve() {
    int N;
    string S;
    cin >> N >> S;

    map<char, int> move_to_idx = {{'R', 0}, {'P', 1}, {'S', 2}};
    
    vector<vector<int>> dp(N, vector<int>(3));
    dp[0][(move_to_idx[S[0]] + 1) % 3] = 1;
    for (int i = 1; i < N; i++) {
        int draw = move_to_idx[S[i]];
        int win = (move_to_idx[S[i]] + 1) % 3;

        dp[i][draw] = max(dp[i - 1][(draw + 1) % 3], dp[i - 1][(draw + 2) % 3]);
        dp[i][win] = max(dp[i - 1][(win + 1) % 3], dp[i - 1][(win + 2) % 3]) + 1;
    }

    cout << max({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]}) << endl;
    
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