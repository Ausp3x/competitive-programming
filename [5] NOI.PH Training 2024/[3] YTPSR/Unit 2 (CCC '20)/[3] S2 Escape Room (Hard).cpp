// 人外有人，天外有天
// author: Ausp3x

#pragma GCC optimize("O3, fast-math")
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
template<class T> // lower_bound and upper_bound are broken
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF32 = 0x3f3f3f3f;
lng const INF64 = 0x3f3f3f3f3f3f3f3f;

int const N = 4'000;
bool gvst[N + 1][N + 1];
bool vst[N * N + 1];
int adjl[N * N + 4'000'000];
int loc[N * N];

bool can_escape(int n, int m, vector<vector<int>> grid) {
    memset(loc, -1, sizeof(loc));

    int cnt = -1, cur = -1;
    priority_queue<tuple<int, short, short>, vector<tuple<int, short, short>>, greater<tuple<int, short, short>>> pq;
    pq.push({1, 1, 1});
    gvst[1][1] = true;
    while (!pq.empty()) {
        auto [p, i, j] = pq.top();
        pq.pop();

        if (p > cur) {
            cnt++;
            cur = p;
            loc[cur] = cnt;
            adjl[cnt] = -cur;
        }
        cnt++;
        adjl[cnt] = grid[i][j];

        if (i + 1 <= n && !gvst[i + 1][j]) {
            pq.push({int(i + 1) * j, i + 1, j});
            gvst[i + 1][j] = true;
        }

        if (j + 1 <= m && !gvst[i][j + 1]) {
            pq.push({int(i) * (j + 1), i, j + 1});
            gvst[i][j + 1] = true;
        }
    }
    cnt++;
    adjl[cnt] = -INF32;

    deque<int> q;
    q.pb(1);
    vst[1] = true;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop_front();

        int i = loc[cur];
        while (adjl[i + 1] > 0) {
            i++;
            if (!vst[adjl[i]] && loc[adjl[i]] != -1) {
                q.pb(adjl[i]);
                vst[adjl[i]] = true;
            }
        }
    }

    return vst[n * m];
}

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }
