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
    vector<map<int, bool>> adjm(n);
    vector<pair<int, int>> edgl(m);
    for (auto &[s, t] : edgl) {
        cin >> s >> t;
        s--;
        t--;
        adjm[s][t] = true;
    }
    
    map<pair<int, int>, bool> in_shortest_path;
    queue<pair<int, vector<pair<int, int>>>> bfs;
    vector<int> dis(n, -1);
    bfs.push({0, {}});
    dis[0] = 0;
    while (!bfs.empty()) {
        auto [cur, edges] = bfs.front();
        bfs.pop();

        if (cur == n - 1) {
            for (auto &e : edges) {
                in_shortest_path[e] = true;
            }

            break;
        }

        for (auto &[nxt, chk] : adjm[cur]) {
            if (dis[nxt] != -1) {
                continue;
            }

            edges.push_back({cur, nxt});
            bfs.push({nxt, edges});
            dis[nxt] = dis[cur] + 1;
            edges.pop_back();
        }
    }

    int shortest_path_len = in_shortest_path.size();
    if (shortest_path_len == 0) {
        for (int i = 0; i < m; i++) {
            cout << -1 << endl;
        } 

        return;
    }

    /*
    for (auto &[e, chk] : in_shortest_path) {
        cout << e.first << ' ' << e.second << ' ' << endl;
    }
    //*/

    for (auto &[s, t] : edgl) {
        if (!in_shortest_path[{s, t}]) {
            cout << shortest_path_len << endl;

            continue;
        }

        adjm[s][t] = false;

        queue<pair<int, int>> bfs;
        vector<int> dis(n, -1);
        bfs.push({0, 0});
        dis[0] = 0;
        while (!bfs.empty()) {
            auto [cur, d] = bfs.front();
            bfs.pop();

            for (auto &[nxt, chk] : adjm[cur]) {
                if (dis[nxt] != -1 || !chk) {
                    continue;
                }

                bfs.push({nxt, d + 1});
                dis[nxt] = d + 1;
            }
        }

        cout << dis[n - 1] << endl;

        adjm[s][t] = true;
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