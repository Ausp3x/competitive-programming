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

struct Dijkstra {
    int n;
    vector<vector<bool>> is_proc;
    vector<vector<lng>> dis;
    priority_queue<tuple<lng, int, bool>, vector<tuple<lng, int, bool>>, greater<tuple<lng, int, bool>>> unproc;

    Dijkstra(const vector<int> &src, int n, const vector<bool> &has_horse, const vector<vector<pair<int, int>>> &adjl): n(n) {
        is_proc.resize(2);
        is_proc[0].resize(n + 1);
        is_proc[1].resize(n + 1);
        dis.resize(2);
        dis[0].resize(n + 1, INF64);
        dis[1].resize(n + 1, INF64);

        for (int u : src) {
            dis[0][u] = 0;
            unproc.push({dis[0][u], u, 0});
        }
        while (!unproc.empty()) {
            auto [d, cur, cur_chk] = unproc.top();
            unproc.pop();

            if (is_proc[cur_chk][cur]) {
                continue;
            }
            is_proc[cur_chk][cur] = true;

            bool nxt_chk = cur_chk | has_horse[cur];
            for (auto [nxt, w] : adjl[cur]) {
                if (nxt_chk)
                    w /= 2;
                
                if (dis[cur_chk][cur] + w < dis[nxt_chk][nxt]) {
                    dis[nxt_chk][nxt] = dis[cur_chk][cur] + w;
                    unproc.push({dis[nxt_chk][nxt], nxt, nxt_chk});
                }
            }
        }
    }

    lng getMinDistance(int u) {
        return min(dis[0][u], dis[1][u]);
    }
};

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    vector<bool> has_horse(n + 1);
    for (int i = 0; i < h; i++) {
        int a;
        cin >> a;
        
        has_horse[a] = true;
    }
    vector<vector<pair<int, int>>> adjl(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjl[u].pb({v, w});
        adjl[v].pb({u, w});
    }

    Dijkstra Marian({1}, n, has_horse, adjl);
    Dijkstra Robin({n}, n, has_horse, adjl);
    
    lng ans = INF64;
    for (int i = 1; i <= n; i++) 
        ans = min(ans, max(Marian.getMinDistance(i), Robin.getMinDistance(i)));

    cout << (ans == INF64 ? -1 : ans) << endl;

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