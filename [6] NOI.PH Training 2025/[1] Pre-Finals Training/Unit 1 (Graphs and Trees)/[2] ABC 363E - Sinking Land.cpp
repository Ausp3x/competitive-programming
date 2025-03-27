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

int N = 100'005;
vector<pair<int, int>> dx_dy = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

void solve() {
    int h, w, y;
    cin >> h >> w >> y;
    vector<vector<int>> A(h + 2, vector<int>(w + 2));
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> A[i][j];

    int cur = 0;
    vector<int> sunk(N);
    vector<vector<bool>> vst(h + 2, vector<bool>(w + 2));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 0; i <= h + 1; i++) {
        pq.push({A[i][0], i, 0});
        pq.push({A[i][w + 1], i, w + 1});
    }
    for (int j = 0; j <= w + 1; j++) {
        pq.push({A[0][j], 0, j});
        pq.push({A[h + 1][j], h + 1, j});
    }
    while (!pq.empty()) {
        auto [tmp, i_cur, j_cur] = pq.top();
        pq.pop();

        if (vst[i_cur][j_cur])
            continue;
        vst[i_cur][j_cur] = true;

        cur = max(cur, A[i_cur][j_cur]);

        if (A[i_cur][j_cur] > 0)
            sunk[cur]++;

        for (auto &[di, dj] : dx_dy) {
            int i_nxt = i_cur + di;
            int j_nxt = j_cur + dj;

            if (i_nxt < 0 || i_nxt > h + 1 || j_nxt < 0 || j_nxt > w + 1)
                continue;

            pq.push({A[i_nxt][j_nxt], i_nxt, j_nxt});
        }
    }

    for (int i = 1; i <= y; i++) {
        sunk[i] += sunk[i - 1];
        cout << h * w - sunk[i] << endl;
    }
    
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