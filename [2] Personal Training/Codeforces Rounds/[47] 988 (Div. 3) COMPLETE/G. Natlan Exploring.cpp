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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int const N = 1'000'005;
int const MOD = 998244353;

vector<vector<int>> factors(N);

void solve() {
    int n;
    cin >> n;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;
    
    // vector<lng> dp(n);
    // dp[0] = 1;
    // for (int i = 0; i < n; i++)
    //     for (int j = i + 1; j < n; j++)
    //         if (gcd(A[i], A[j]) != 1)
    //             dp[j] += dp[i];

    // cout << dp[n - 1] << endl;

    function<vector<pair<int, int>>(int)> get = [&](int x) {
        int len = factors[x].size();
        vector<pair<int, int>> vals(1 << len);
        vals[0] = {1, 1};
        for (int i = 1; i < (1 << len); i++) {
            int j = __lg(i);
            vals[i].fi = vals[i ^ (1 << j)].fi * factors[x][j];
            vals[i].se = -vals[i ^ (1 << j)].se;
        }

        return vals;
    };

    vector<lng> dp(n), sums(N);
    dp[0] = 1;
    for (auto [a, b] : get(A[0])) 
        sums[a]++;
    
    lng add = 1;
    for (int i = 1; i < n; i++) {
        auto V = get(A[i]);

        lng sub = 0;
        for (auto [a, b] : V) {
            sub += (sums[a] * (b + MOD) % MOD + MOD) % MOD;
            sub %= MOD;
        }

        dp[i] = (add - sub + MOD) % MOD;
        
        add += dp[i];
        add %= MOD;
        for (auto [a, b] : V) {
            sums[a] += dp[i];
            sums[a] %= MOD;
        }
    }

    cout << dp[n - 1] << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < N; i++) {
        if (!factors[i].empty())
            continue;

        for (int j = i; j < N; j += i)
            factors[j].pb(i);
    }

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}