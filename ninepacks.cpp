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

int N = 100005;

void solve() {
    int H_len;
    cin >> H_len;
    vector<int> H(H_len);
    for (int &h : H)
        cin >> h;
    int B_len;
    cin >> B_len;
    vector<int> B(B_len);
    for (int &b : B)
        cin >> b;

    int turn1 = 0;
    vector<vector<int>> hdp(2, vector<int>(N, INF32));
    hdp[0][0] = 0;
    for (int i = 0; i < H_len; i++) {
        for (int j = 0; j < N; j++)
            hdp[turn1 ^ 1][j] = hdp[turn1][j];

        for (int j = 0; j + H[i] < N; j++)
            hdp[turn1 ^ 1][j + H[i]] = min(hdp[turn1 ^ 1][j + H[i]], hdp[turn1][j] + 1);

        turn1 ^= 1;
    }

    int turn2 = 0;
    vector<vector<int>> bdp(2, vector<int>(N, INF32));
    bdp[0][0] = 0;
    for (int i = 0; i < B_len; i++) {
        for (int j = 0; j < N; j++)
            bdp[turn2 ^ 1][j] = bdp[turn2][j];

        for (int j = 0; j + B[i] < N; j++)
            bdp[turn2 ^ 1][j + B[i]] = min(bdp[turn2 ^ 1][j + B[i]], bdp[turn2][j] + 1);

        turn2 ^= 1;
    }

    int ans = INF32;
    for (int i = 1; i < N; i++) {
        if (hdp[turn1][i] == INF32 || bdp[turn2][i] == INF32)
            continue;

        ans = min(ans, hdp[turn1][i] + bdp[turn2][i]);
    }

    if (ans == INF32)
        cout << "impossible" << endl;
    else
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