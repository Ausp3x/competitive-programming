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
template<class T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int turn = 0;
    vector<vector<lng>> dp(2, vector<lng>(k + 1, INF64));
    dp[0][0] = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        
        int ttl = a + b;
        vector<lng> req(ttl + 1);
        for (int i = 1; i < ttl; i++) {
            if (a > b)
                swap(a, b);

            req[i] += req[i - 1];
            req[i] += a;
            b--;
        }
        req[ttl] = req[ttl - 1]; 

        dp[turn ^ 1][0] = 0;
        for (int i = 1; i <= k; i++)
            dp[turn ^ 1][i] = INF64;

        for (int i = 0; i <= k; i++) {
            if (dp[turn][i] == INF64)
                break;

            for (int j = 0; j <= ttl; j++) {
                if (i + j > k)
                    break;

                dp[turn ^ 1][i + j] = min(dp[turn ^ 1][i + j], dp[turn][i] + req[j]);
            }
        }

        turn ^= 1;    
    }

    cout << (dp[turn][k] == INF64 ? -1 : dp[turn][k]) << endl;
    
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