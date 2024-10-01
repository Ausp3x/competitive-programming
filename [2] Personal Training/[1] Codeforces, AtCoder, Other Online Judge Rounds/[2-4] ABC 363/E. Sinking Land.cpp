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

void solve() {
    int H, W, Y;
    cin >> H >> W >> Y;
    vector<vector<int>> grid(H + 2, vector<int>(W + 2));
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> grid[i][j];

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    for (int i = 1; i <= H; i++) {
        pq.push({grid[i][1], i, 1});
        if (W != 1)
            pq.push({grid[i][W], i, W});
    }
    for (int j = 2; j < W; j++) {
        pq.push({grid[1][j], 1, j});
        if (H != 1)
            pq.push({grid[H][j], H, j});
    }
    
    vector<int> di = {-1,  0, 0, 1};
    vector<int> dj = { 0, -1, 1, 0};

    lng ans = H * W;
    vector<vector<bool>> has_sunk(H + 2, vector<bool>(W + 2));
    for (int day = 1; day <= Y; day++) {
        while (!pq.empty()) {
            if (get<0>(pq.top()) > day)
                break;

            auto [g, i_cur, j_cur] = pq.top();
            pq.pop();

            if (has_sunk[i_cur][j_cur])
                continue;
            has_sunk[i_cur][j_cur] = true;

            if (i_cur == 0 || i_cur == H + 1 || j_cur == 0 || j_cur == W + 1)
                continue;

            // cout << g << ' ' << i_cur << ' ' << j_cur << endl;

            ans--;
            
            for (int i = 0; i < 4; i++) {
                int i_nxt = i_cur + di[i];
                int j_nxt = j_cur + dj[i];
                
                pq.push({grid[i_nxt][j_nxt], i_nxt, j_nxt});
            }
        }

        cout << ans << endl;
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