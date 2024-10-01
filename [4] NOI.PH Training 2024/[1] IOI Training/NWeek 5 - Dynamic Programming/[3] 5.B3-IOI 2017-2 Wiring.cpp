// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O1, O2, O3, Ofast, unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include "wiring.h"
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

vector<int> st1_R, st1_B;
vector<vector<lng>> memo;
lng st1_dp(int i, int j) {
    if (i < 0 || j < 0)
        return INF64;

    if (memo[i][j] != INF64)
        return memo[i][j];
    
    if (i == 0 && j == 0)
        return memo[i][j] = abs(st1_R[i] - st1_B[j]);

    return memo[i][j] = min(min({st1_dp(i - 1, j), st1_dp(i, j - 1), st1_dp(i - 1, j - 1)}) + abs(st1_R[i] - st1_B[j]), INF64);
}

lng min_total_length(vector<int> R, vector<int> B) {
    int n = R.size(), m = B.size();
    
    if (n <= 200 && m <= 200) {
        st1_R = R;
        st1_B = B;
        memo.resize(n, vector<lng>(m, INF64));

        #ifdef DEBUG
        cout << st1_dp(n - 1, m - 1) << endl;
        #endif DEBUG
        #ifndef DEBUG
        return st1_dp(n - 1, m - 1);
        #endif
    }

    if (R.back() < B[0]) {
        int i = n - 1, j = m - 1;
        lng ans = 0;
        while (i >= 0 && j >= 0) {
            ans += B[j] - R[i];
            
            i--;
            j--;
        }

        while (i >= 0) {
            ans += B[0] - R[i];
            i--;
        }

        while (j >= 0) {
            ans += B[j] - R[n - 1];
            j--;
        }

        #ifdef DEBUG
        cout << ans << endl;
        #endif DEBUG
        #ifndef DEBUG
        return ans;
        #endif
    }

    vector<pair<lng, int>> V;
    V.pb({-INF32, -1});
    for (int i = 0; i < n; i++)
        V.pb({R[i], 0});
    for (int i = 0; i < m; i++)
        V.pb({B[i], 1});
 
    sort(V.begin(), V.end());
    V[0].se = 1 - V[1].se;

    int l = n + m;
    vector<lng> prf(l + 1);
    for (int i = 1; i <= l; i++)
        prf[i] = prf[i - 1] + V[i].fi;

    lng prv = 1;
    vector<lng> dp(l + 1);
    for (int i = 1; i <= l; i++) {
        // get current same-color block
        int j = i;
        while (j < l && V[j].se == V[j + 1].se)
            j++;
        
        for (int k = prv; k < i; k++)
            dp[k] = min(dp[k], dp[k - 1] + (V[i].fi - V[k].fi));
        
        lng mn = dp[i - 1], sm = 0;
        for (int k = i; k <= j; k++) {
            sm += (V[k].fi - V[i - 1].fi);
            
            int cur = 2 * i - k - 1;
            if (cur >= prv) {
                lng add = V[i - 1].fi * (i - cur) + (prf[cur - 1] - prf[i - 1]);
                mn = min(mn, dp[cur - 1] + add);
            }

            dp[k] = mn + sm;
        }

        prv = i;
        i = j;
    }

    return dp[l];
}

#ifdef DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> R(n);
        for (int &r : R)
            cin >> r;
        vector<int> B(m);
        for (int &b : B)
            cin >> b;

        cout << min_total_length(R, B) << endl;
    }

    return 0;
}
#endif