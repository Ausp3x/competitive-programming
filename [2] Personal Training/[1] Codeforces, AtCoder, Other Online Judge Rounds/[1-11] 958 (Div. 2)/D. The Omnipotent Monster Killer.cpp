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
lng const INF64 = 0x7e7e7e7e7e7e7e7e;

int n, m = 20;
vector<lng> A;
vector<vector<int>> adjl;
// root node i of current subtree, j× multiplier of node i
vector<vector<lng>> memo;
lng dp(int cur, int prv) {
    for (int i = 1; i < m; i++)
        memo[cur][i] = A[cur] * i;
    
    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        dp(nxt, cur);

        lng min_val = INF64, i_of_min = -1;
        for (int i = 1; i < m; i++) {
            if (memo[nxt][i] < min_val) {
                min_val = memo[nxt][i];
                i_of_min = i;
            }
        }

        lng sec_min_val = INF64;
        for (int i = 1; i < m; i++) {
            if (i == i_of_min)
                continue;
            
            memo[cur][i] += min_val;
            sec_min_val = min(sec_min_val, memo[nxt][i]);
        }
        memo[cur][i_of_min] += sec_min_val;
    }
    
    lng res = INF64;
    for (int i = 1; i < m; i++)
        res = min(res, memo[cur][i]);
    
    return res;
}

void solve(int t) {
    cin >> n;
    A.clear();
    A.resize(n);
    for (lng &a : A)
        cin >> a;
    adjl.clear();
    adjl.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adjl[x].pb(y);
        adjl[y].pb(x);
    }
    memo.clear();
    memo.resize(n, vector<lng>(m, INF64));

    cout << dp(0, -1) << endl;

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve(t);
    }

    return 0;
}