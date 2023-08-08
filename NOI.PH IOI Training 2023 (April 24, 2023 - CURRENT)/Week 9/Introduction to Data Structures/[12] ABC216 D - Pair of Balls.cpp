// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

int const INF32 = 1 << 30;
lng const INF64 = 1ll << 60;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> top_ball_idxs;
    vector<queue<int>> balls(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;

        while (k--) {
            int a;
            cin >> a;

            balls[i].push(a);
        }

        int cur = balls[i].front();
        top_ball_idxs[cur].push_back(i);

        queue<pair<int, int>> to_be_deleted;
        if (top_ball_idxs[cur].size() == 2) {
            to_be_deleted.push({top_ball_idxs[cur][0], top_ball_idxs[cur][1]});
        }

        while (!to_be_deleted.empty()) {
            auto [idx1, idx2] = to_be_deleted.front();
            to_be_deleted.pop();

            if (!balls[idx1].empty()) {
                balls[idx1].pop();
            }

            if (!balls[idx1].empty()) {
                int cur = balls[idx1].front();
                top_ball_idxs[cur].push_back(idx1);
            
                if (top_ball_idxs[cur].size() == 2) {
                    to_be_deleted.push({top_ball_idxs[cur][0], top_ball_idxs[cur][1]});
                }
            }

            if (!balls[idx2].empty()) {
                balls[idx2].pop();
            }

            if (!balls[idx2].empty()) {
                int cur = balls[idx2].front();
                top_ball_idxs[cur].push_back(idx2);
            
                if (top_ball_idxs[cur].size() == 2) {
                    to_be_deleted.push({top_ball_idxs[cur][0], top_ball_idxs[cur][1]});
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (!balls[i].empty()) {
            cout << "No" << endl;

            return;
        }
    }
 
    cout << "Yes" << endl;

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