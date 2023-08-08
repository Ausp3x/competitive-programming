// 人外有人，天外有天
// author: Ausp3x

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
typedef long long             lng;
typedef unsigned int          uint;
typedef unsigned long long    ulng;
using namespace std;
using namespace __gnu_pbds;

// #define TROUBLESHOOT

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adjl(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adjl[a].push_back(b);
        adjl[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;

        int ans = 0;
        map<int, int> vertex_dis;
        queue<pair<int, int>> bfs;
        bfs.push({x, 0});
        vertex_dis[x] = 0;
        while (!bfs.empty()) {
            auto [cur, d] = bfs.front();
            bfs.pop();

            if (d > k) {
                continue;
            }

            ans += cur;

            for (int nxt : adjl[cur]) {
                if (nxt == x || vertex_dis[nxt] > 0) {
                    continue;
                }

                bfs.push({nxt, d + 1});
                vertex_dis[nxt] = d + 1;
            }
        }

        cout << ans << endl;
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifdef TROUBLESHOOT
    auto start = chrono::high_resolution_clock::now();
#endif

#ifdef TROUBLESHOOT
    // testing code
#endif

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

#ifdef TROUBLESHOOT
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << duration.count() << " microseconds\n";
#endif

    return 0;
}