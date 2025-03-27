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
    vector<vector<char>> grid(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    function<bool(vector<int>)> willVoteAlvaro = [&](vector<int> A) {
        int cnt = 0;
        for (int a : A) 
            cnt += (grid[a / n][a % n] == 'A');

        return cnt >= 2;
    };

    map<pair<int, int>, int> memo;
    function<int(int, int)> dp = [&](int a, int b) {
        if (a < -1 || b < -1)
            return -INF32;
        
        if (a == -1 && b == -1)
            return 0;

        if (memo.contains({a, b}))
            return memo[{a, b}];

        int res = 0;
        if (a == b) {
            res = max(res, dp(a - 1, b - 2) + willVoteAlvaro({a, n + b - 1, n + b}));
            res = max(res, dp(a - 2, b - 1) + willVoteAlvaro({a - 1, a, n + b}));
        } 
        if (a - b == 1) 
            res = max(res, dp(a - 2, b - 1) + willVoteAlvaro({a - 1, a, n + b}));
        if (b - a == 1)
            res = max(res, dp(a - 1, b - 2) + willVoteAlvaro({a, n + b - 1, n + b}));
        if (a >= b)
            res = max(res, dp(a - 3, b) + willVoteAlvaro({a - 2, a - 1, a}));
        if (b >= a)
            res = max(res, dp(a, b - 3) + willVoteAlvaro({n + b - 2, n + b - 1, n + b}));

        return memo[{a, b}] = res;
    };

    // dp(n - 1, n - 1);
    // for (auto &[k, v] : memo) 
    //     cout << '[' << k.fi << ' ' << k.se << "] " << v << endl;

    cout << dp(n - 1, n - 1) << endl;
    
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