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
    int n;
    lng x;
    cin >> n >> x;
    vector<lng> A(n);
    for (lng &a : A)
        cin >> a;

    if (x == 1) {
        cout << 1 << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
        A[i] = gcd(A[i], x);

    vector<lng> facs;
    for (lng i = 1; i * i <= x; i++) {
        if (x % i != 0)
            continue;

        facs.pb(i);
        if (i * i != x)
            facs.pb(x / i);
    }

    int len = facs.size();
    unordered_map<lng, int> cnts;
    vector<unordered_map<lng, int>> dp(2);
    dp[0][1] = 0;
    for (int i = 1; i < len; i++)
        dp[0][facs[i]] = INF32;

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1)
            continue; 

        if (cnts[A[i]] == 32)
            continue;
        cnts[A[i]]++;

        int nxt = cur ^ 1;
        for (auto &[k, v] : dp[cur])
            dp[nxt][k] = v;
        for (auto &[k, v] : dp[cur]) {
            lng k2 = gcd(k * A[i], x);
            dp[nxt][k2] = min(dp[nxt][k2], v + 1);
        }

        cur ^= 1;
    }

    cout << (dp[cur][x] == INF32 ? -1 : dp[cur][x]) << endl;

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