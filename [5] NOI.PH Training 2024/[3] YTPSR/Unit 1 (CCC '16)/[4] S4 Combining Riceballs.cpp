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
    cin >> n;
    vector<int> A(n);
    for (int &a : A)
        cin >> a;

    vector<int> A_prf(n + 1);
    for (int i = 1; i <= n; i++)
        A_prf[i] = A_prf[i - 1] + A[i - 1];

    // for (int a : A_prf)
    //     cout << a << ' ';
    // cout << endl;

    map<pair<int, int>, int> M;
    vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));    
    function<bool(int, int)> dp = [&](int l, int r) {
        if (memo[l][r] != -1)
            return memo[l][r];

        if (l == r) {
            M[{r, A_prf[r] - A_prf[l - 1]}] = l;
            return memo[l][r] = 1;
        }

        memo[l][r] = 0;
        for (int i = l; i < r; i++) {
            int l_sum = A_prf[i] - A_prf[l - 1];
            int r_sum = A_prf[r] - A_prf[i];
            if (dp(l, i) && dp(i + 1, r))
                memo[l][r] |= (l_sum == r_sum);
        }

        int cur = 0;
        for (int i = l; i < r - 1; i++) {
            cur += A[i - 1];

            if (!dp(l, i))
                continue;

            int j = M[{r, cur}];
            if (j <= i + 1)
                continue;

            memo[l][r] |= dp(i + 1, j - 1);
        }

        if (memo[l][r] == 1)
            M[{r, A_prf[r] - A_prf[l - 1]}] = l;
        return memo[l][r];
    };

    dp(1, n);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (memo[i][j] == -1)
                memo[i][j] = 0;
            // cout << memo[i][j] << ' ';

            if (memo[i][j] == 1)
                ans = max(ans, A_prf[j] - A_prf[i - 1]); 
        }
        // cout << endl;
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