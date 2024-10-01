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

/*
 .  given n chips, place each one on a certain point 1 <= x <= 10 -> starting state
 .  four operations:
 .  1. add i, add i + 1, remove i + 2
 .  2. remove i, remove i + 1, add i + 2
 .  3. add 1, remove 2
 .  4. remove 1, add 2
 .  for each starting state, cost is minimum possible number of chips left after all operations
 .  find the number of starting states that have m cost
*/

int const MOD = 998244353;

int MAXF = 30;
vector<int> fib(MAXF);

int MAXN = 55010;
vector<bool> chk(MAXN);

int calc(int x) {
    int res = 0;
    for(int i = MAXF - 1; i >= 1; i--)
        if (x >= fib[i]) {
            x -= fib[i];
            res++;
        }

    return res;
}
 
int MAXn = 1010;
vector<vector<lng>> dp(MAXN, vector<lng>(MAXn));

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    
    int N = n * fib[x];
    for (int i = 1; i <= N; i++)
        chk[i] = calc(i) == m;

    dp[0][0] = 1;
    for (int k = 1; k <= x; k++)
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= n; j++)
                if (i >= fib[k] && j > 0) {
                    dp[i][j] += dp[i - fib[k]][j - 1];
                    dp[i][j] %= MOD;
                }

    lng ans = 0;
    for (int i = 0; i <= N; i++)
        if (chk[i]) {
            ans += dp[i][n];
            ans %= MOD;
        }

    cout << ans << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < MAXF; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}