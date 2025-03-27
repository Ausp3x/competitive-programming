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

void solve() {
    int n;
    cin >> n;
    vector<lng> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    map<lng, vector<int>> M;
    vector<int> P(n + 1, -1);
    M[0].pb(0);
    for (int i = 1; i <= n; i++) {
        A[i] += A[i - 1];
        if (!M[A[i]].empty()) 
            P[i] = M[A[i]].back();
        M[A[i]].pb(i);
    }

    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (P[i] != -1)
            dp[i] = max(dp[i], dp[P[i]] + 1);
    }

    cout << dp[n] << endl;
    
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