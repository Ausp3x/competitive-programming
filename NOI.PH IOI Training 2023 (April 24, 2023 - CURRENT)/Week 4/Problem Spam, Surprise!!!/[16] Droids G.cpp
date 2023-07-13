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

bool bipartiteMatching(auto &graph, int u, auto &match, auto &seen) {
    for (auto &[v, val] : graph[u]) {
        if (val && !seen[v]) {
            seen[v] = true;

            if (match[v] == 0 || bipartiteMatching(graph, match[v], match, seen)) {
                match[v] = u;
                return true;
            }
        }
    }

    return false;
}

int maxBipartiteMatching (auto &graph) {
    int res = 0;
    map<int, int> match;
    for (auto &[u, links] : graph) {
        map<int, bool> seen;
        if (bipartiteMatching(graph, u, match, seen)) {
            res++;
        }
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    map<int, map<int, bool>> graph;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
    }

    cout << maxBipartiteMatching(graph) << endl;

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
    cin >> t;
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