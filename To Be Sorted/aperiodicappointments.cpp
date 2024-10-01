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
typedef __int128     lli;
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int N, K;
    cin >> N >> K;

    if (K == 1) {
        cout << N - 1 << endl;
        return;
    }

    int exp = 0;
    lli K_pow = 1;
    vector<lli> K_pows, K_pow_sums;
    K_pows.pb(1);
    K_pow_sums.pb(1);
    while (K_pow_sums.back() + K_pow * K <= N) {
        exp++;
        K_pow *= K;
        K_pows.pb(K_pow);
        K_pow_sums.pb(K_pow_sums.back() + K_pow);
    }

    if (exp >= K) {
        lng ans = K_pow_sums[K - 1];
        N -= K_pow_sums[K];
        ans += N;
        N = 0;

        cout << ans << endl;
        return;
    }

    lng ans = 0;
    for (int i = exp; i > 0; i--) {
        lli cur = K_pow_sums[i];
        
        lng q = N / cur;
        N -= q * cur;
        ans += q * K_pow_sums[i - 1];

        // cout << i << ' ' << N << endl;
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