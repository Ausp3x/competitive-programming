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

int const MOD = 1'000'000'007;
int const A_max = 1023;
int const inv_10000 = 285'700'002;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;
    vector<int> P(n);
    for (int &p : P)
        cin >> p;

    vector<array<int, A_max + 1>> dp(2);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) { 
        int turn = i % 2;
        for (int j = 0; j <= A_max; j++)
            dp[turn ^ 1][j] = 0;
        
        for (int j = 0; j <= A_max; j++) {
            // add
            dp[turn ^ 1][j ^ A[i]] += 1ll * dp[turn][j] * P[i] % MOD * inv_10000 % MOD;
            dp[turn ^ 1][j ^ A[i]] %= MOD;

            // didn't add
            dp[turn ^ 1][j] += 1ll * dp[turn][j] * (10'000 - P[i]) % MOD * inv_10000 % MOD;
            dp[turn ^ 1][j] %= MOD;
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j < 10; j++)
    //         cout << dp[i][j] << ' ';
    //     cout << endl;
    // }

    int ans = 0;
    for (int j = 0; j <= A_max; j++) {
        ans += 1ll * j * j % MOD * dp[n % 2][j] % MOD;
        ans %= MOD;
    }

    cout << ans << endl;
    
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