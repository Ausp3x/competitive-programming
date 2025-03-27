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
lng c;
vector<lng> A;
vector<vector<int>> adjl;

vector<array<lng, 2>> memo;
void dp(int cur, int prv) {
    memo[cur][0] = 0;
    memo[cur][1] = A[cur];
    for (int nxt : adjl[cur]) {
        if (nxt == prv)
            continue;

        dp(nxt, cur);
        memo[cur][0] += max(memo[nxt][0], memo[nxt][1]);
        memo[cur][1] += max(memo[nxt][0], memo[nxt][1] - 2 * c);
    }

    return;
}

void solve() {
    cin >> n >> c;
    A.clear();
    A.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    adjl.clear();
    adjl.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adjl[u].pb(v);
        adjl[v].pb(u);
    }

    memo.clear();
    memo.resize(n + 1);
    dp(1, 1);

    cout << max(memo[1][0], memo[1][1]) << endl;

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