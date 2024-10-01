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

int n;
vector<tuple<int, int, int>> mice;
double m;
vector<double> M_inv;

int compareFloat(double a, double b) {
    double err = 1e-9;
    if (abs(a - b) < err)
        return 0;

    return (a > b ? 1 : -1);
}

double getDistance(int i, int j, int cnt) {
    assert(-1 <= i && i < n && -1 <= j && j < n);
    auto [xi, yi, si] = (i == -1 ? make_tuple(0, 0, INF32) : mice[i]);
    auto [xj, yj, sj] = (j == -1 ? make_tuple(0, 0, INF32) : mice[j]);

    return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj)) * M_inv[cnt];
}

// v, D
vector<vector<pair<double, double>>> memo;
pair<double, double> dp(int msk, int end) {
    if (compareFloat(memo[msk][end].fi, INF32) == -1 && compareFloat(memo[msk][end].se, INF32) == -1)
        return memo[msk][end];

    int prv_msk = msk - (1 << end);
    if (prv_msk == 0) {
        double D_cur = getDistance(-1, end, 0);
        double v_cur = D_cur / get<2>(mice[end]);

        return memo[msk][end] = {v_cur, D_cur};
    } 

    int cnt = 0;
    for (int prv_end = 0; prv_end < n; prv_end++)
        if (prv_msk & (1 << prv_end))
            cnt++;

    double v_min = INF32;
    double D_min = INF32;
    for (int prv_end = 0; prv_end < n; prv_end++) {
        if (!(prv_msk & (1 << prv_end)))
            continue;

        auto [v_prv, D_prv] = dp(prv_msk, prv_end);

        double D_cur = D_prv + getDistance(prv_end, end, cnt);
        double v_cur = max(v_prv, D_cur / get<2>(mice[end]));

        if (compareFloat(v_cur, v_min) <= 0) {
            v_min = v_cur;
            D_min = min(D_min, D_cur);
        }
    }
    
    return memo[msk][end] = {v_min, D_min};
}

void solve() {
    cin >> n;
    mice.clear();
    mice.resize(n);
    for (auto &[x, y, s] : mice)
        cin >> x >> y >> s;
    cin >> m;
    
    M_inv.clear();
    M_inv.resize(n, 1);
    for (int i = 1; i < n; i++)
        M_inv[i] = M_inv[i - 1] / m;

    memo.clear();
    memo.resize(1 << n, vector<pair<double, double>>(n, {INF32, INF32}));
    for (int j = 0; j < n; j++)
        memo[0][j] = {0, 0};

    for (int i = 0; i < n; i++)
        dp((1 << n) - 1, i);

    double ans = INF32;
    for (int i = 0; i < n; i++)
        ans = min(ans, dp((1 << n) - 1, i).fi);

    cout << setprecision(15) << ans << endl;

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