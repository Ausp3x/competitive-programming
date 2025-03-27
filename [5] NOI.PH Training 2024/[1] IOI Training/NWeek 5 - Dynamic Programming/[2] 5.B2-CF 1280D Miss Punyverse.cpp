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

int n, m;
vector<lng> B, W;
vector<vector<int>> adjl;

vector<int> sze;
void getSizes(int cur, int prv) {
    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        getSizes(nxt, cur);
        sze[cur] += sze[nxt];
    }

    return;
}

bool isBetter(const pair<int, lng> &x, const pair<int, lng> &y) {
    if (x.fi > y.fi)
        return true;
    
    if (x.fi == y.fi)
        return x.se > y.se;

    return false;
}

// win, adv
vector<vector<pair<int, lng>>> memo;
void dp(int cur) {
    int turn = 0;
    vector<vector<pair<int, lng>>> cur_memo(2, vector<pair<int, lng>>(m + 1, {-1, -INF64}));
    cur_memo[0][1] = {0, W[cur] - B[cur]};
    for (int nxt : adjl[cur]) { 
        if (sze[nxt] > sze[cur])
            continue;
        
        dp(nxt);
        
        for (int i = 1; i <= m; i++)
            cur_memo[turn ^ 1][i] = {-1, -INF64};
        for (int nxt_m = 1; nxt_m <= min(m, sze[nxt]); nxt_m++) 
            for (int i = 1; i <= m; i++) {
                if (cur_memo[turn][i].fi == -1)
                    break;

                if (i + nxt_m - 1 <= m) {
                    pair<int, lng> joint = cur_memo[turn][i];
                    joint.fi += memo[nxt][nxt_m].fi;
                    joint.se += memo[nxt][nxt_m].se;
                    if (isBetter(joint, cur_memo[turn ^ 1][i + nxt_m - 1]))
                        cur_memo[turn ^ 1][i + nxt_m - 1] = joint;
                }

                if (i + nxt_m <= m) {
                    pair<int, lng> disjoint = cur_memo[turn][i];
                    disjoint.fi += memo[nxt][nxt_m].fi + (memo[nxt][nxt_m].se > 0);
                    if (isBetter(disjoint, cur_memo[turn ^ 1][i + nxt_m]))
                        cur_memo[turn ^ 1][i + nxt_m] = disjoint;
                }
            }

        turn ^= 1;
    }

    for (int i = 1; i <= m; i++)
        memo[cur][i] = cur_memo[turn][i];

    return;
}

void solve() {
    cin >> n >> m;
    B.clear();
    B.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> B[i];
    W.clear();
    W.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> W[i];
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;

        adjl[x].pb(y);
        adjl[y].pb(x);
    }

    sze.clear();
    sze.resize(n + 1, 1);
    getSizes(1, 0);
    
    // for (int x : sze)
    //     cout << x << ' '; 
    // cout << endl << endl;

    memo.clear();
    memo.resize(n + 1, vector<pair<int, lng>>(m + 1, {-1, -INF64}));
    dp(1);

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         cout << memo[i][j].fi << ' ';
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++)
    //         if (memo[i][j].se == -INF64)
    //             cout << "-inf ";
    //         else
    //             cout << memo[i][j].se << ' ';
    //     cout << endl;
    // }
    // cout << endl;

    cout << memo[1][m].fi + (memo[1][m].se > 0) << endl;

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