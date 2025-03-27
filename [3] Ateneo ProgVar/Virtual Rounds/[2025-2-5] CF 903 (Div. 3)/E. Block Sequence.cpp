// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    vector<pair<int, int>> P;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];

        int j = i + A[i];
        if (j <= n)
            P.pb({j, i});
    }
    
    sort(P.begin(), P.end(), greater<pair<int, int>>());

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        while (!P.empty()) {
            if (P.back().fi != i)
                break;

            dp[i] = max(dp[i], dp[P.back().se - 1] + P.back().fi - P.back().se + 1);
            P.pop_back();
        }
    }

    cout << n - dp[n] << endl;

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